/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-27 06:50:39
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
//第一反应直接四个嵌套for，果然超时
// int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
//     int res = 0;
//     for (int i = 0; i < ASize; i++) {
//         for (int j = 0; j < BSize; j++) {
//             for (int k = 0; k < CSize; k++) {
//                 for (int l = 0; l < DSize; l++) {
//                     if (0 == A[i] + B[j] + C[k] + D[l]) {
//                         res++;
//                     }
//                 }
//             }
//         }
//     }
//     return res;
// }
// //找互为相反数的数对，该方法只考虑了两对相反数，未考虑其中一个值为0的情况
// int opposNum(int* a, int aSize, int* b, int bSize) {
//     int res = 0;
//     for (int i = 0; i < aSize; i++) {
//         for (int j = 0; j < bSize; i++) {
//             if (a[i] == -b[j]) {
//                 res++;
//             }
//         }
//     }
//     return res;
// }
// int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
//     int ab = 0;
//     int cd = 0;
//     int ac = 0;
//     int bd = 0;
//     int ad = 0;
//     int bc = 0;

//     ab = opposNum(A, ASize, B, BSize);
//     cd = opposNum(C, CSize, D, DSize);
//     ac = opposNum(A, ASize, C, CSize);
//     bd = opposNum(B, BSize, D, DSize);
//     ad = opposNum(A, ASize, D, DSize);
//     bc = opposNum(B, BSize, C, CSize);

//     int res = ab * cd + ac * bd + ad * bc;
//     return res;
// }
//用的哈希表
struct hashTable {
    int            key;
    int            val;
    UT_hash_handle hh;
};
int fourSumCount(int *A, int ASize, int *B, int BSize, int *C, int CSize, int *D, int DSize) {
    struct hashTable *hashtable = NULL;
    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < BSize; ++j) {
            int ikey = A[i] + B[j];    //键是二者和

            struct hashTable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if (tmp == NULL) {
                struct hashTable *tmp = malloc(sizeof(struct hashTable));
                tmp->key = ikey, tmp->val = 1;
                HASH_ADD_INT(hashtable, key, tmp);
            } else {
                tmp->val++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < CSize; ++i) {
        for (int j = 0; j < DSize; ++j) {
            int ikey = -C[i] - D[j];    //键是二者和，为c+d的相反数

            struct hashTable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);    //在a+b中查找相反数
            if (tmp != NULL) {
                res += tmp->val;    //精髓
            }
        }
    }
    return res;
}
//自定义哈希表，只处理int，内存和处理时间都大幅缩短
#define mod 100003

typedef struct Link {
    int          key;
    int          val;
    struct Link *next;
} Link;

typedef struct {
    Link *arr[mod];
} MyHash;

Link *_get(MyHash *hash, int key) {
    int   idx  = abs(key) % mod;
    Link *node = hash->arr[idx];
    while (node && node->key != key) {
        node = node->next;
    }
    return node;
}

void _insert(MyHash *hash, int key, int val) {
    Link *node = _get(hash, key);
    if (!node) {
        node           = malloc(sizeof(Link));
        node->key      = key;
        node->val      = val;
        int idx        = abs(key) % mod;
        node->next     = hash->arr[idx];
        hash->arr[idx] = node;
    } else {
        node->val = val;
    }
}

void _add(MyHash *hash, int key) {
    Link *node = _get(hash, key);
    if (!node) {
        node           = malloc(sizeof(Link));
        node->key      = key;
        node->val      = 1;
        int idx        = abs(key) % mod;
        node->next     = hash->arr[idx];
        hash->arr[idx] = node;
    } else {
        node->val += 1;
    }
}

void _initHash(MyHash *hash) {
    memset(hash->arr, 0, sizeof(hash->arr));
}

void _freeHash(MyHash *hash) {
    for (int i = 0; i < mod; ++i) {
        if (hash->arr[i]) {
            Link *node = hash->arr[i];
            while (node) {
                Link *next = node->next;
                free(node);
                node = next;
            }
        }
    }
}

int fourSumCount(int *A, int ASize, int *B, int BSize, int *C, int CSize, int *D, int DSize) {
    MyHash hash;
    _initHash(&hash);
    int res = 0;
    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < BSize; ++j) {
            _add(&hash, A[i] + B[j]);
        }
    }
    for (int i = 0; i < CSize; ++i) {
        for (int j = 0; j < DSize; ++j) {
            Link *node = _get(&hash, -(C[i] + D[j]));
            if (node) res += node->val;
        }
    }
    _freeHash(&hash);
    return res;
}
