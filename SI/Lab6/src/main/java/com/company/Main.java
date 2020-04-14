package com.company;

import java.security.InvalidKeyException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.util.Scanner;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.ShortBufferException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;

public class Main {
    public static void show(byte[] aux) {
        for (byte el : aux)
            System.out.print(String.format("%02X ", el));
        System.out.println();
    }

    public static Key keyGeneration(String pasw) throws NoSuchAlgorithmException, InvalidKeySpecException {
        char[] password = pasw.toCharArray();
        byte[] salt = new byte[16];
        int iteration_cnt = 1000;
        int key_size = 128;

        SecureRandom myPRNG = new SecureRandom();
        myPRNG.nextBytes(salt);
        IvParameterSpec ivSpec = new IvParameterSpec(salt);
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
        PBEKeySpec pbekSpec = new PBEKeySpec(password, salt, iteration_cnt, key_size);
        SecretKey myAESPBKey = new SecretKeySpec(keyFactory.generateSecret(pbekSpec).getEncoded(), "AES");

        return myAESPBKey;
    }

    public static void encryptKey(Key key) throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            ShortBufferException, IllegalBlockSizeException, BadPaddingException {

        Scanner scanner = new Scanner(System.in);
        System.out.println("You have home options: ");
        System.out.println("1. CBC");
        System.out.println("2. OFB");
        System.out.println("3. CFB");
        int option = scanner.nextInt();
        scanner.close();
        Cipher myAES = null;
        switch (option) {
            case 1:
                myAES = Cipher.getInstance("AES/CBC/NoPadding");
                break;

            case 2:
                myAES = Cipher.getInstance("AES/OFB/NoPadding");
                break;

            case 3:
                myAES = Cipher.getInstance("AES/CFB/NoPadding");
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + option);
        }

        myAES.init(Cipher.ENCRYPT_MODE, key);
        byte[] plaintext = new byte[16];
        plaintext = "messingaroundAES".getBytes();
        byte[] ciphertext = new byte[16];
        int cLength = myAES.update(plaintext, 0, plaintext.length, ciphertext, 0);
        cLength += myAES.doFinal(ciphertext, cLength);
        System.out.println("plaintext: ");
        show(plaintext);
        System.out.println("ciphertext");
        show(ciphertext);
    }

    public static void main(String[] args)
            throws InvalidKeySpecException, NoSuchAlgorithmException, IllegalBlockSizeException, InvalidKeyException,
            BadPaddingException, ShortBufferException, NoSuchPaddingException {
        String password = "SI_Lab6!";
        Key key = keyGeneration(password);
        encryptKey(key);
    }
}
