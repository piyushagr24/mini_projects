package com.example;
import java.util.Scanner;

public class ex2_rockpapsic {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("1 -> Rock");
        System.out.println("2 -> Paper");
        System.out.println("3 -> Scissors");
        System.out.println("Enter your input:");
        int human = sc.nextInt();
        switch(human) {
            case 1 -> System.out.println("You have chosen rock");
            case 2 -> System.out.println("You have chosen paper");
            case 3 -> System.out.println("You have chosen scissors");
            default -> System.out.println("Please enter valid number");
        }
        int min = 1;
        int max = 3;
    System.out.print("Computer has chosen: ");
    int comp = (int)(Math.random()*(max-min+1)+min);
    System.out.println(comp);
        switch (comp) {
            case 1 -> System.out.println("Computer have chosen rock.");
            case 2 -> System.out.println("Computer have chosen Paper.");
            case 3 -> System.out.println("Computer have chosen Scissor.");
        }
        if (human==comp) {
            System.out.println("It's a tie!");
        }
        else if ((human==1 && comp==3)||(human==2 && comp==1)||(human==3 && comp==2)) {
            System.out.println("You win!");
        }
        else if ((human==1 && comp==2)||(human==2 && comp==3)||(human==3 && comp==1)) {
            System.out.println("Computer wins!\nBetter luck next time.");
        }
    }
    
}
