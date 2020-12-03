/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-03 11:41:18
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
/*暴力破解，超出时间限制*/
bool isPrime(int n) {
    if (n <= 1) return false;
    if (2 == n) return true;
    for (int i = 2; i < n; i++) {
        if (0 == n % i) {
            return false;
        }
    }
    return true;
}
/*优化-用时较长*/
bool isPrime(int n) {
    if (n <= 1) return false;
    if (2 == n) return true;
    for (int i = 2; i * i <= n; i++) {
        if (0 == n % i) {
            return false;
        }
    }
    return true;
}
/*二次优化-素数要出现只可能出现在 6x 的相邻两侧。*/
//比上面的方法快了将近2/3
bool isPrime(int n) {
    if (n <= 1) return false;
    if (2 == n || 3 == n) return true;
    if (1 != n % 6 && 5 != n % 6) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (0 == n % i || 0 == n % (i + 2)) return false;
    }
    return true;
}
int countPrimes(int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(i)) {
            res++;
        }
    }
    return res;
}
/*埃式筛选法*/
//只用了上述最快的方法的1/10的时间
int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    //默认为0，如果不是质数则置1
    int *isPrime = calloc(n, sizeof(int));
    int  res     = 0;
    int  cnt     = 0;
    for (int i = 2; i < n; i++) {
        if (!isPrime[i]) {
            res += 1;
            // printf("i----%d\r\n", i);
            if ((long long)i * i < n) {
                //将当前数的倍数置1
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 1;
                    cnt++;
                    // printf("%d__cnt:%d\r\n", j, cnt);
                }
            }
        }
    }
    printf("%d\r\n", cnt);
    return res;
}
/*线性筛*/
/**
 * 核心点在于：如果x可以被primes(i)整除，那么对于合数y = x*primes(i+1)x而言，
 * 它一定在后面遍历到x/(primes(i))*primes(i+1)这个数的时候会被标记，其他同理.
 * 这保证了每个合数只会被其「最小的质因数」筛去，即每个合数被标记一次。
 */
int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    int *isPrime = calloc(n, sizeof(int));
    // primes 数组表示当前得到的质数集合。
    int primes[n], primesSize = 0;
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        if (!isPrime[i]) {
            //记录质数
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize && i * primes[j] < n; ++j) {
            cnt++;
            printf("primes[%d]--%2d,i:%3d,priSize--%3d,i*p:%3d __cnt:%d\r\n", j, primes[j], i, primesSize, i * primes[j], cnt);
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                printf("++++\r\n");
                break;
            }
        }
    }
    return primesSize;
}
//线性筛和埃氏筛，当n =100时，后者需要跑102次，前者只需要73次
//两种方式最大的差别是，埃筛是先找质数，在找质数的倍数进行标记
//这样会重复标记；线性筛，则是先找质数，并在过程中标记第一个质
//数的倍数，避免了重复标记。
