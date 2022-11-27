/* An example of using the flex C++ scanner class. */

%option c++ noyywrap

%{
int mylineno = 0;
%}

string	\"[^\n"]+\"

ws	[ \t]+

alpha	[A-Za-z]
dig	[0-9]
IDENT	({alpha}|{dig}|\$)({alpha}|{dig}|_|\.|\-|\/|\$)*
num1	[-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2	[-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number	{num1}|{num2}

%%

{ws}	/* skip blanks and tabs */

"/*" {
	int c;

	while((c = yyinput()) != 0)
	{
		if(c == '\n')
			++mylineno;
		else if(c == '*') {
			if((c = yyinput()) == '/')
				break;
			else
				unput(c);
		}
	}
}

{number}	std::cout << "number " << YYText() << '\n';

\n		mylineno++;

{IDENT}		std::cout << "name " << YYText() << '\n';

{string}	std::cout << "string " << YYText() << '\n';

%%