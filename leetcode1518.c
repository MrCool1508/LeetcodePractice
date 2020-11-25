/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 17:26:56
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
// int numWaterBottles(int numBottles, int numExchange) {
//     int res      = 0;
//     int temp     = 0;
//     int emptyBot = 0;

//     res      = numBottles;    //最开始全喝完
//     emptyBot = numBottles;    //全部变成空瓶
//     while (emptyBot >= numExchange) {
//         temp = emptyBot % numExchange;    //空瓶能换新酒后剩余的空瓶数量
//         emptyBot /= numExchange;          //恰好能全部换新酒，空瓶即新酒的数量
//         res += emptyBot;                  //更新喝到的酒的数量
//         if (temp) {
//             emptyBot += temp;
//         }
//         // if (temp) {
//         //     res += emptyBot / numExchange;               //更新能喝到酒的数量
//         //     emptyBot = emptyBot / numExchange + temp;    //更新空瓶数量
//         // } else {
//         //     emptyBot /= numExchange;    //恰好能全部换新酒，空瓶即新酒的数量
//         //     res += emptyBot;            //更新喝到的酒的数量
//         // }
//     }
//     return res;
// }

// int numWaterBottles(int numBottles, int numExchange) {
//     int res      = 0;
//     int temp     = 0;
//     int emptyBot = 0;

//     res      = numBottles;    //最开始全喝完
//     emptyBot = numBottles;    //全部变成空瓶
//     while (emptyBot >= numExchange) {
//         temp = emptyBot % numExchange;    //空瓶能换新酒后剩余的空瓶数量
//         emptyBot /= numExchange;          //恰好能全部换新酒，空瓶即新酒的数量
//         res += emptyBot;                  //更新喝到的酒的数量
//         if (temp) {
//             emptyBot += temp;
//         }
//     }
//     return res;
// }
/**
 * 下述方法无法通过连续测试，因为是全局变量。
 *
 * */
// int first = 1;
// int res   = 0;
// int numWaterBottles(int numBottles, int numExchange) {
//     if (first) {
//         res   = numBottles;
//         first = 0;
//     }
//     //本次能喝到的酒
//     int changeBottles = numBottles / numExchange;    //新换的酒
//     res += changeBottles;
//     printf("res:%d, cb:%d\r\n", res, changeBottles);
//     if (changeBottles >= 1) {
//         return numWaterBottles(changeBottles + numBottles % numExchange, numExchange);
//     } else {
//         return res;
//     }
// }

int numWaterBottles(int numBottles, int numExchange) {
    if (numBottles < numExchange) {
        return numBottles;
    } else {
        return numBottles - numBottles % numExchange + numWaterBottles(numBottles / numExchange + numBottles % numExchange, numExchange);
    }
}
