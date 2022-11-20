//
//
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <locale>
#include <codecvt>

#include <cassert>

class unicodebuf : public std::streambuf
{
    const size_t buffer_size_ = 1024;
    std::wstreambuf *sbuf_;
    char *buffer_;
    wchar_t *wbuffer_;
    // context for the compression
public:
    unicodebuf(std::wstreambuf *sbuf)
        : sbuf_(sbuf)
        , buffer_(new char[buffer_size_ * 3])
        , wbuffer_(new wchar_t[buffer_size_])
    {
        // initialize compression context
    }
    ~unicodebuf() {
        delete[] this->buffer_;
    }
    int underflow() {
        if ( this->gptr() == this->egptr() ) {
            auto size = sbuf_->sgetn(wbuffer_, buffer_size_);

            char *p = this->buffer_;
            for ( int i = 0; i < size; ++i )
            {
                int code = (this->wbuffer_[i] >> 8) & 255;
                if ( code == 0 )
                    *p++ = char(this->wbuffer_[i] & 255);
                else {
                    char xx[20];
                    snprintf(xx, sizeof(xx), "\\U%02x%02x", code, this->wbuffer_[i] & 255);
                    *p++ = xx[0];
                    *p++ = xx[1];
                    *p++ = xx[2];
                    *p++ = xx[3];
                    *p++ = xx[4];
                    *p++ = xx[5];
                }
            }

            this->setg(this->buffer_, this->buffer_, p);
        }
        return this->gptr() == this->egptr()
            ? std::char_traits<char>::eof()
            : std::char_traits<char>::to_int_type(*this->gptr());
    }
};


void
usage()
{
    std::cerr << "Usage: prog file\n";
    exit(1);
}

int main(int argc, char** argv)
{
    if ( argc < 2 )
        usage();
    {
        std::wifstream fin(argv[1], std::ios::binary);
        assert(fin.good() && "Cannot open file...");

        // fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
        for ( wchar_t ch; fin.get(ch); )
        {
            std::cout << std::hex << ch << " ";
        }
        std::cout << '\n';
    }
    {
        std::wifstream fin(argv[1], std::ios::binary);

        assert(fin.good() && "Cannot open file...");

        fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

        unicodebuf   sbuf(fin.rdbuf());
        std::istream  in(&sbuf);

        for ( char ch; in.get(ch); )
        {
            std::cout << ch;
        }
    }
}
