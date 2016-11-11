#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
  char *buffer;

  gid_t gid;
  uid_t uid;

  gid = getegid();
  uid = geteuid();

  printf("[*] gid is %d\n", gid);
  printf("[*] uid is %d\n", uid);
}
