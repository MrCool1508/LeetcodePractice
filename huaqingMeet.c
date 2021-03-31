/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2021-03-22 20:39:17
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
// #define CMD_SEND 1
// #define CMD_RECEIVE 2
// #define CMD_SET 3
// #define CMD_GET 4
// #define CMD_RESET 5

// uint8_t cmd_list[] = {
//     CMD_SEND,
//     CMD_RECEIVE,
//     CMD_SET,
//     CMD_GET,
//     CMD_RESET,
//     0,
// };

// char* cmd_list_name[] = {
//     "cmd_send",
//     "cmd_receive",
//     "cmd_set",
//     "cmd_get",
//     "cmd_reset",
//     "",
// };

// int get_cmd_name_by_indx(uint8_t idx, char* cmd_name) {
//     uint8_t i = 0;
//     printf("cd_l_s:%d, uin_s:%d\r\n", sizeof(cmd_list), sizeof(uint8_t));
//     while (cmd_list[i] && i < sizeof(cmd_list) / sizeof(uint8_t)) {
//         if (cmd_list[i] == idx) {
//             break;
//         }
//         i++;
//         printf("i:%d\r\n", i);
//     }
//     if (i >= sizeof(cmd_list) / sizeof(uint8_t)) {
//         return -1;
//     } else {
//         strcpy(cmd_name, cmd_list_name[i]);
//         return 0;
//     }
// }

// static void report_status(void *parameter) {
//     int   ret;
//     char *num;
//     num = bl_get_num(parameter);
//     if (num == NULL) {
//         printf("get num error\n");
//     }
//     ret = atoi(num);
//     send_status(ret);
// }

// static void max_number(struct list_struct *l) {
//     unsigned int        len = 0;
//     struct list_struct *p, *cur;
//     for (p = 1; p != NULL; p = p->next) {
//         len++;
//     }
//     if (len > MAXLEN) {
//         printf("find title %s", p->title);
//     }
// }

// #define CONTROL_ID_SET_STATUS 20

// struct control {
//     int      cmd;
//     int      len;
//     uint8_t *id;
//     uint8_t  type;
// };

// int set_control_status(uint8_t *id) {
//     int            ret;
//     struct control ctrl;
//     ctrl.cmd  = 42;
//     ctrl.len  = strlen(id);
//     ctrl.id   = id;
//     ctrl.type = CONTROL_ID_SET_STATUS;

//     if (0 == strcmp(id, "RUN")) {
//         // ret = send_ctrl_to_client(&ctrl);    //二者相同
//         printf("send ctrl to client\r\n");
//         ret = 2;
//     } else {
//         // reset_ctrl(&ctrl);
//         printf("ahhhh\r\n");
//     }
//     printf("sonFuncRet:%d\r\n", ret);
//     return ret;
// }

// #define MAX_STATUS_LEN 20
// #define FILENAME "111.txt"
// int save_status_to_file(const char *file) {
//     char *buf = NULL;
//     int   ret = -1;
//     int   fd  = -1;

//     buf = malloc(MAX_STATUS_LEN);
//     if (!buf) {
//         printf("curr_ret:!buf:%d\r\n", ret);
//         return ret;
//     }
//     // printf("buf:%s, len:%d\r\n", buf, strlen(buf));
//     fd = open(file, O_RDWR);
//     printf("fd:%d\r\n", fd);
//     if (fd < 0) {
//         printf("%s failed to open file %s\r\n", file);
//         return ret;
//     }
//     //    get_running_status(buf);
//     ret = write(fd, buf, MAX_STATUS_LEN);
//     if (buf) {
//         printf("free buf\r\n");
//         free(buf);
//     }
//     if (fd >= 0) {
//         printf("close file\r\n");
//         close(fd);
//     }
//     return ret;
// }

#define CMD_SEND 1
#define CMD_RECEIVE 2
#define CMD_SET 3
#define CMD_GET 4
#define CMD_RESET 5
#define FILENAME "111.txt"
uint8_t cmd_list[] = {
    CMD_SEND,
    CMD_RECEIVE,
    CMD_SET,
    CMD_GET,
    CMD_RESET,
};

int read_cmd_from_config(const char *file, uint8_t *out_cmd) {
    uint8_t cmd = 0;
    uint8_t idx = 0;
    int     ret = 0;
    int     fd  = -1;

    if (!file && !out_cmd) {
        return -1;
    }
    fd = open(file, O_RDONLY);
    if (fd > 0) {
        read(fd, &cmd, sizeof(uint8_t));
        printf("cmd:%d\r\n", cmd);
        idx = cmd - '0';
        printf("idx:%d\r\n", idx);
        printf("cmd_list[%d]:%d\r\n", idx, cmd_list[idx]);
        out_cmd = &cmd_list[idx];
        printf("out_cmd:%d\r\n", *out_cmd);
        close(fd);
    } else {
        printf("open %s failed\r\n", file);
        ret = -2;
    }
    return ret;
}

// struct response {
//     int type;
//     int value;
// };

// static void send_response(const char *type, const char *value) {
//     struct response *res = (struct response *)malloc(sizeof(struct response));
//     // printf("%d, %d----!\r\n", atoi(type), atoi(value));

//     // int test  = atoi(type);
//     // res->type = test;
//     res->type  = atoi(type);
//     res->value = atoi(value);
//     printf("%d, %d----!\r\n", res->type, res->value);
//     //    send_to_client(res);
// }

int main(int argc, char const *argv[]) {
    char rev_name[20] = {0};
    printf("hello:\r\n");
    // send_response("20", "35");
    // printf("%d\r\n", get_cmd_name_by_indx(6, rev_name));
    uint8_t *test_id = {"RUN"};

    // int testNum = set_control_status(test_id);
    // printf("testNum:%d\r\n", testNum);
    // int ret = save_status_to_file(FILENAME);
    int ret = read_cmd_from_config(FILENAME, test_id);
    printf("ret:%d\r\n", ret);

    // printf("%d\r\n", atoi(NULL));
    printf("end\r\n");
    printf("%s\r\n", rev_name);
    char *test_ptr = NULL;
    if (!test_ptr) {
        printf("test succees\r\n");
    }
    return 0;
}

// No.1
// 有可能向atoi传入NULL。

// No.2
// for循环运行到最后一个元素时，p != NULL,但是p->next ==NULL，所以p->title这时会出现错误。

// No.3
// 1、传入参数type和value未做非空判断及处理。
// 2、结构体指针struct response *res没有做malloc初始化。

// No.4
// 1、ret未赋初值。
// 2、if - else的else执行语句中未对ret进行处理。

// No.5
// 1、line226，buf = (char*)malloc(MAX_STATUS_LEN);。应该进行强转。
// 2、open中用的是只读，但是下面有写操作，所以应该把O_RDONLY改为O_RDWR，允许读写。

// No.6
// 1、CMD_SEND,CMD_RECEIVE,CMD_SET,CMD_GET,CMD_RESET未定义具体数值。
// 2、2、read是否读取成功未做判断。
// 3、未对cmd、idx做范围判断，若出现异常， idx存在越界的可能性。
// 4、out_cmd不应该为指针类型，cmd_list[idx] 为一个值，不能将值赋给指针。如果需要out_cmd为指针类型，则应该改为out_cmd =
// &cmd_list[idx]。

// No.7
// 1、CMD_SEND，CMD_RECEIVE，CMD_SET，CMD_GET，CMD_RESET未定义具体的数值。
// 2、return -1;这个条件永远进不去。
// 3、strcpy函数后面缺少分号。

// No.8 局部变量的内存空间会在函数结束后被释放。可以用参数传递的方式解决这个问题。
// “return current_name”这里有问题。函数返回的是局部变量指针，
