/*************************************************************************
	> File Name: cut_mp3.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com 
	> Created Time: Sunday, November 08, 2015 AM11:06:45 HKT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>

#define PART_LEN ((float)(18*1024*1024))
#define ARR_LEN (256)
#define PER_MINUTE2SEN (60)


static int get_shell_stdout(const char *shell_cmd, char *shell_stdout, const int len)
{
    FILE *pp = NULL;

    if (shell_cmd == NULL)
        return -1;

    if ((pp = popen(shell_cmd,  "r" )) == NULL) {
        printf("###ERR: Open shell Cmd Err.\r\n");
        return -2;
    }

    while (fgets(shell_stdout, len, pp));
    pclose(pp);

    return 0;
}

static int get_cut_part(const int file_size)
{
    int part = 0;
    float f_part = 0;
    if (file_size < 0)
        return -1;

    f_part = ((float)file_size / PART_LEN);
    part = (int)f_part ;
    if(f_part - (int)f_part > 0)
        part = (int)f_part + 1;
    return part;
}

static int get_file_duration(const char *file_name)
{
    int ret = 0,i_duration = 0;
    char cmd[ARR_LEN] = {0}, str_duration[ARR_LEN] = {0};

    if (file_name == NULL)
        return -1;

    sprintf(cmd,"ffprobe -i %s -show_format -v quiet | sed -n \'s/duration=//p\'", file_name); 
    ret = get_shell_stdout(cmd, str_duration, sizeof(str_duration)); 
    if (ret < 0) {
        printf("###ERR: Exec Cmd Err.\r\n");
        return -2;
    }
    
    i_duration = (int)strtof(str_duration, NULL);
    printf("%d\r\n", i_duration);

    return  i_duration; 
}

static int get_file_size(const char *file_name)
{
    int ret = 0, i_size = 0;
    char cmd[ARR_LEN] = {0}, str_size[ARR_LEN] = {0};

    if (file_name == NULL)
        return -1;

    sprintf(cmd,"ffprobe -i %s -show_format -v quiet | sed -n \'s/size=//p\'", file_name); 
    ret = get_shell_stdout(cmd, str_size, sizeof(str_size)); 
    if (ret < 0) {
        printf("###ERR: Exec Cmd Err.\r\n");
        return -2;
    }
    
    i_size = (int)strtof(str_size, NULL);
    printf("%d\r\n", i_size);

    return  i_size; 
}




int main(int argc, char **argv)
{

    char cmd[ARR_LEN] = {0};
    int  duration = 0, i_size;
    int  hh = 0, mm = 0, ss = 0,  ret = 0, ms = 0,  part = 0, part_index = 1, time_len = 0;
    char *file_name = NULL;

    if(argc != 2) {
        printf("###INFO: Please Chech Input Parm Again.\r\n");
        printf("example: ./prog sample.mp3\r\n");
        return -1;
    }

    file_name = argv[1];
    i_size = get_file_size(file_name);
    if (i_size < 0) {
        printf("###ERR: Get File Size Err.\r\n");
        return -2;
    }

    part = get_cut_part(i_size);
    if (part < 0) {
        printf("###ERR: Get Cut Part Err.\r\n");
        return -3;
    }

    duration = get_file_duration(file_name);
    if (duration < 0) {
        printf("###ERR: Get File Duration Err.\r\n");
        return -4;
    }

    time_len = duration/PER_MINUTE2SEN/part;

    for (hh = 0, mm = 0, ss = 0, part_index = 1;
         part_index < part; 
         hh = mm / 60, ms = mm-hh*60, mm += time_len, part_index++) {

        sprintf(cmd, "ffmpeg -i %s -ss %d:%d:%d -t 00:%d:00 -vcodec copy -acodec copy Part%d-%s", 
                file_name, hh, ms, ss, time_len, part_index, file_name);

        ret = system(cmd);  
        if (ret < 0) {
            printf("###ERR: Exec Cmd Err.\r\n");
            return -5;
        }

    } 

    return 0;
}
