class Solution {

    private final static long MOD = 1_000_000_000 + 7;

    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final long[] spread = new long[n + 1];        
        final long[] stop = new long[n + 1];

        if(1 + delay <= n) {
            spread[1 + delay] = 1;
        }
        if(1 + forget <= n) {
            stop[1 + forget] = 1;
        }

        long peopleCount = 1;
        long newPeopleIncomingCount = 0;

        for(int i = 2; i <= n; ++i) {
            newPeopleIncomingCount -= stop[i] % MOD;
            newPeopleIncomingCount += spread[i] % MOD;

            peopleCount += newPeopleIncomingCount % MOD;
            peopleCount -= stop[i] % MOD;
            // System.out.println(i + "<>" + newPeopleIncomingCount + "<>" + peopleCount + "<>" + spread[i] + "<>" + stop[i]);

            final int spreadStart = i + delay;
            if(spreadStart <= n) {
                spread[spreadStart] = newPeopleIncomingCount % MOD;
            }

            final int spreadStop = i + forget;
            if(spreadStop <= n) {
                stop[spreadStop] = newPeopleIncomingCount % MOD;
            }
        }

        return (int) (peopleCount % MOD);
    }

}