//
// Created by yxr on 2018/8/12.
//
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return ceil(log(buckets)/log(minutesToTest/minutesToDie+1));  // log_{T+1}(N)
}
