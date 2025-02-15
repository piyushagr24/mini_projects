package com.example;
import java.util.Random;
import java.util.Scanner;

class game{
    int rndnum,uprbnd,gesnum;
    int score =10;
    boolean flag = false;
    public game(int x){ // constructor
        uprbnd = x;
        Random rnd = new Random();
        rndnum = rnd.nextInt(uprbnd) + 1;
        /* This generates a random integer between 0 (inclusive) and x (exclusive). The Random class's nextInt(int bound) method returns a pseudorandom, uniformly distributed int value between 0 (inclusive) and the specified value (exclusive). */
    }
    public int getrndnum(){
        return rndnum;
    }
    public int getuprbnd(){
        return uprbnd;
    }
// public void intnum(){
//     Scanner sc = new Scanner(System.in);
//     System.out.print("Enter your guess: ");
//     gesnum = sc.nextInt();
//     // if(gesnum == rndnum){
//     //     System.out.println("Congratulations! You gesnumed correctly.");
//     // } else if(gesnum < rndnum){
//     //     System.out.println("Too low. Try again.");
//     // } else {
//     //     System.out.println("Too high. Try again.");
//     // }
// }
public void iscrt(){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter your guess: ");
    gesnum = sc.nextInt();
    sc.close();
    while(flag == false){
    if(gesnum == rndnum){
        System.out.println("Congratulations! You gesnumed correctly.");
        flag = true;
    } else if(gesnum < rndnum){
        System.out.println("Too low. Try again.");
        flag = false;
    } else {
        System.out.println("Too high. Try again.");
        flag = false;
    }
}
}
public void score(){
    if (flag == false){
        score--;
    }
}
}
public class gesnum1 {
    public static void main(String[] args) {
System.out.println("Enter range of guessing:");
Scanner sc = new Scanner(System.in);
int x = sc.nextInt();
sc.close();
game g1 = new game(x);
System.out.println("Welcome,Guess the number between 1-"+g1.getuprbnd());
g1.iscrt();
System.out.println("Your score is " + g1.score);
    }
}