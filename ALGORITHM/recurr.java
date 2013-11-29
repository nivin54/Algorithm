import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger[][] f = new BigInteger[110][110];
        for(int i = 0; i <= 100; i ++)
			for(int j=0;j<=100;j++)
            f[i][j] = new BigInteger("0");
        for(int n = 1; n <= 100; n ++)
            for(int k = 1; k <= n; k ++)
            {
				for(int i=1;i<=k&&(n-i)>=k;i++)
				{
                    f[n][k] = f[n][k].add(f[n-i][k]);
				}
				f[n][k]=f[n][k].add((BigInteger.valueOf(2)).pow(n-k));
			}
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            int k = cin.nextInt();
            System.out.println(f[n][k]);
        }
    }
}
