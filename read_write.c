#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



//函数声明
int open_check(int fd,char *file);
int write_check(int count,char *file);
int read_check(int readcount,char *file);
int close_check(int fd,char *file);





//---------------------------------------------------------------主函数部分--------------------------------------------------------------//
int main(int argc, char const *argv[])
{
	int fd;
	char writebuf[ ] = "hello world";
	char readbuf[20] = {0};
	ssize_t  writecount;
    ssize_t  readcount;

	//打开1.txt
	fd = open("./1.txt",O_RDWR);

	//判断是否打开成功
    open_check(fd,"./1.txt");

    //写入1.txt
    writecount = write(fd, writebuf,sizeof(writebuf) );

    //判断是否写入成功
    write_check(writecount,"./1.txt");

    //清空偏移量
    lseek(fd,0,SEEK_SET);

    //读1.txt
    readcount = read(fd, readbuf, sizeof(readbuf));

    //判断读是否错误
    read_check(readcount,"./1.txt");
     
    //关闭1.txt
     close(fd);
    
    //判断文件是否关闭
    close_check(fd,"./1.txt");

    //打开2.txt
    fd = open("./2.txt",O_RDWR);

    //判断是否打开成功
    open_check(fd,"./2.txt");
    
    //写入2.txt
    writecount = write(fd, readbuf,sizeof(readbuf) );

    //判断是否写入成功
    write_check(writecount,"./2.txt");

    //关闭2.txt
     close(fd);

    return 0 ;
}





//-------------------------------------------------------------函数定义部分-------------------------------------------------------------------------//
//判断是否打开成功
int open_check(int fd,char *file)
{
	if (fd == -1)
	{
		printf("open %serror\n",file);
		printf("fd = %d\n",fd);
		return  -1;
	}
	else{
		printf("success to open %s\n",file);
		printf("fd = %d\n",fd);
	}
	return fd;
}

//判断是否写入成功
ssize_t write_check(ssize_t count,char *file)
{
	if (count == -1)
    {
    	printf("write to %s error\n",file);
    	return -1;
    }
    else{
    	printf("success to write 1.%s\n",file);
    	printf("count = %d\n",count);
    }
	return count;
}

//判断是否读数据成功
int read_check(int readcount,char *file)
{
	 if (readcount == -1)
    {
    	printf("read %s error\n",file);
    	return -1;
    }
    else{
        printf("success to read %s\n",file);
    	return readcount;
    }
}


//判断文件是否退出成功
int close_check(int fd,char *file)
{
	if (fd == -1)
    {
    	printf("close %s error\n",file);
    	return -1;
    }
    else{
    	printf("success to close %s\n",file);
    	return fd;
    }
}