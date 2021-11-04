#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int interface(int fd, int speed, int parity){
    struct termios tty;
    if (tcgetattr(fd,&tty) != 0){
        printf("Error");
        return -1;
    }
    cfsetospeed(&tty,speed);
    cfsetispeed(&tty,speed);
    
    //is this copied from stackoverflow? yes

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
    tty.c_iflag &= ~IGNBRK;
    tty.c_lflag = 0;
    tty.c_oflag = 0;
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 5;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~(PARENB | PARODD);
    tty.c_cflag |= parity;
    return 0;
}
