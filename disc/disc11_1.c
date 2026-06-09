static int product_native(int n, int *a) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= a[i];
    }
    return product;
}

static int product_vectorized(int n, int *a) {
    int result[4];
    
    __m128i prod_v = _mm_set1_epi32(1);

    for (int i = 0; i < n - 3; i += 4) {
        prod_v = _mm_mullo_epi32(prod_v, _mm_loadu_si128((__m128i *)&a[i]));
    }
    
    _mm_storeu_si128((__m128i *)result, prod_v);
    
    for (int i = 0; i < n%4; i++) {
        result[0] *= a[n-1-i];
    }
    
    return result[0] * result[1] * result[2] * result[3];
}

static int add20_native(int n, int *a) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 20) {
            sum += 20;
        }
    }
    return sum;
}

static int add20_vectorized(int n, int *a) {
    int result[4];

    __m128i sum_v = _mm_set1_epi32(0);
    int32_t twenty[4] = {20, 20, 20, 20};

    __m128i vec_twenty = _mm_loadu_si128((__m128i *)twenty);
    
    for (int i = 0; i < n - 3; i += 4) {
        __m128i vec_a = _mm_loadu_si128((__m128i *)&a[i]);
        sum_v = _mm_add_epi32(sum_v, _mm_and_si128(_mm_cmpeq_epi32(vec_a, vec_twenty), vec_twenty));
    }
    
    _mm_storeu_si128((__m128i *)result, sum_v);
    for (int i = 0; i < n%4; i++) {
        if (a[n-1-i] == 20) {
            result[0] += 20;
        }
    }
    
    return result[0] + result[1] + result[2] + result[3];
}