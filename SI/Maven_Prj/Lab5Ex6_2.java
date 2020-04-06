package SI.Maven_Prj;

import java.math.BigInteger;

public class Lab5Ex6_2 {

    public static BigInteger sqrt(BigInteger x) {
        BigInteger div = BigInteger.ZERO.setBit(x.bitLength() / 2);
        BigInteger div2 = div;
        for (;;) {
            BigInteger y = div.add(x.divide(div)).shiftRight(1);
            if (y.equals(div) || y.equals(div2))
                return y;
            div2 = div;
            div = y;
        }
    }

    public static void main(String[] args) {
        BigInteger n = new BigInteger("837210799");
        BigInteger e1 = new BigInteger("7");
        BigInteger e2 = new BigInteger("17");
        BigInteger d1 = new BigInteger("478341751");
        BigInteger d2;
        BigInteger P = n;
        BigInteger k;
        BigInteger S;
        k = d1.multiply(e1.subtract(new BigInteger("1"))).divide(n).add(new BigInteger("1"));

        System.out.println("k: " + k);
        S = (k.multiply(n.add(new BigInteger("1"))).add(new BigInteger("1")).subtract(e1.multiply(d1))).divide(k);
        System.out.println("p+q: " + S);
        BigInteger Δ;
        Δ = S.pow(2).subtract(new BigInteger("4").multiply(P));
        System.out.println("Δ: " + Δ);
        BigInteger x1;
        BigInteger x2;
        BigInteger sqrt_Δ = sqrt(Δ);

        BigInteger ɸ = P.subtract(S).add(new BigInteger("1"));
        x1 = S.add(sqrt_Δ).divide(new BigInteger("2"));
        x2 = S.subtract(sqrt_Δ).divide(new BigInteger("2"));
        System.out.println("x₂: " + x1);
        System.out.println("x₂: " + x2);

        d2 = e2.modPow(new BigInteger("-1"), ɸ);
        System.out.println("d₂: " + d2);
    }
}