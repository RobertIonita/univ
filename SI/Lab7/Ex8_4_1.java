package SI.Lab7;

import java.net.MalformedURLException;
import java.net.URL;
import java.security.cert.Certificate;
import java.security.cert.X509Certificate;
import java.io.*;
import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLPeerUnverifiedException;

public class Ex8_4_1 {
    public static void main(String[] args) {
        String https = "https://self-signed.badssl.com";
        URL url;
        HttpsURLConnection con;
        try {
            // try to open connection
            url = new URL(https);
            con = (HttpsURLConnection) url.openConnection();
            InputStream conIS = con.getInputStream();
            // print SSL/TLS cipher-suite for this connection
            System.out.println("Cipher Suite : " + con.getCipherSuite());
            System.out.println("\n");
            // enumerate through the certification chain
            Certificate[] certs = con.getServerCertificates();
            for (Certificate cert : certs) {
                System.out.println("Cert Public Key Algorithm : " + cert.getPublicKey().getAlgorithm());
                System.out.println("\n");
            }
            // print data from the url
            BufferedReader br = new BufferedReader(new InputStreamReader(conIS));
            String input;
            while ((input = br.readLine()) != null) {
                System.out.println(input);
            }
            br.close();
        } catch (SSLPeerUnverifiedException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}