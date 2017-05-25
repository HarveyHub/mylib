#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "comm.h"

using namespace std;



int main(int argc, char** argv)
{
	double start, end;
	start = getCurrentTimeStamp();
    cout << "this is main cpp" << endl;
    string str = "my string is ";
    int x = 2;
    val2str(x, str);
    MSG(str);
    ERR("ERR error test");
    MSG("message test");
    WARN("warnning test");

    string str_num = "3.1415926f";
    double d_num = 0;
    str2val(str_num, d_num);
    MSG(d_num);

    int ch;
    printf("optind:%,opter:%d\n",optind,opterr);
    printf("--------------------------\n");
    while ((ch = getopt(argc, argv, "ab:c:de::")) != -1)
    {
        printf("optind: %d\n", optind);
        switch (ch)
        {
        case 'a':
            printf("HAVE option: -a\n\n");
            break;
        case 'b':
            printf("HAVE option: -b\n");
            printf("The argument of -b is %s\n\n", optarg);
            break;
        case 'c':
            printf("HAVE option: -c\n");
            printf("The argument of -c is %s\n\n", optarg);
            break;
        case 'd':
            printf("HAVE option: -d\n");
            break;
        case 'e':
            printf("HAVE option: -e\n");
            printf("The argument of -e is %s\n\n", optarg);
            break;
        case '?':
            printf("Unknown option: %c\n",(char)optopt);
            break;
        }
    }
	end = getCurrentTimeStamp();
	MSG("cost " << (end -start) << "us" );
	usleep(1000);
	end = getCurrentTimeStamp();
	MSG("cost " << (end -start) << "us" );
    MSG("Program ends");
	return 0;

}
