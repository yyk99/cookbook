#include <iostream>
#include <future>
#include <thread>

int return_eight()
{
    return 8;
}

int t1()
{
    // future from a packaged_task
    std::packaged_task<int()> task([] { return 7; }); // wrap the function
    std::future<int> f1 = task.get_future();  // get a future
    std::thread t(std::move(task)); // launch on a thread

    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, return_eight);

    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([&p] { p.set_value_at_thread_exit(9); }).detach();

    std::cout << "Waiting..." << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: "
        << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
    t.join();

    return 0;
}

int t2()
{
    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, return_eight);

    std::cout << "f2.valid(): " << f2.valid() << "\n";
    f2.wait();
    std::cout << "f2.valid(): " << f2.valid() << "\n";
    std::cout 
        << "Results are: "
        << f2.get() 
        << '\n';
    std::cout << "f2.valid(): " << f2.valid() << "\n";

    return 0;
}

int main()
{
    t2();
}