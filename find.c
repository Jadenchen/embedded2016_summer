#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>


void find (DIR *dir){

	struct dirent *ptr;
	 while((ptr = readdir(dir))!=NULL) {

		char pathname[100];
		struct stat buf;
		sprintf(pathname, "/home/menzx/Desktop/learning/homework/%s", ptr);
		stat(pathname, &buf);

		if(S_ISREG(buf.st_mode)){
			 printf("%s: file\n", ptr->d_name);
			 
		}else{
			printf("%s : directory\n", ptr->d_name);
			DIR *dir1;
			dir1 = open("ptr->d_name");

			find("dir1");
		}
	 }
}


int main() {
    DIR * dir;
//	struct dirent * ptr;
//	int i;
	dir =opendir(“/home/menzx/Desktop/learning/homework”);
/*	while((ptr = readdir(dir))!=NULL) {
			char pathname[100];
			struct stat buf;
			sprintf(pathname,"/etc/rc.d/%s", ptr->d_name);
			stat(pathname, &buf);
			
			if(S_ISREG(buf.st_mode))
					printf("%s: file\n", ptr->d_name);
					
			else
					printf("%s: directory\n", ptr->d_name);
			}
			*/
	find (dir);
	 closedir(dir);
	return 0;																							
																							
}
