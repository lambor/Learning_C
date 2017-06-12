#include <stdio.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

#define SHOWHOST

void show_time(long timeval)
{
        char *cp;
        cp = ctime(&timeval);
        printf("%12.12s",cp + 3);
}

void show_info(struct utmp *record) {
        if(record->ut_type != USER_PROCESS)
                return;
        printf("%-8.8s",record->ut_name);
        printf(" ");
        printf("%-8.8s",record->ut_line);
        printf(" ");
        show_time(record->ut_time);
        printf(" ");
#ifdef SHOWHOST
        if(record->ut_host[0] != '\0')
                printf("(%s)",record->ut_host);
#endif
        printf("\n");
}

int main()
{
	struct utmp *utmpfp,
		    *utmp_next();
	if(utmp_open(UTMP_FILE) == -1)
	{
		perror(UTMP_FILE);
		exit(1);
	}
	while((utmpfp = utmp_next()) != ((struct utmp *)NULL))
		show_info(utmpfp);
	utmp_close();
	return 0;
}


