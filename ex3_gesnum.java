// // package com.example;
// import java.util.Scanner;

// class game{
//     int rndnum;
//     int gesnum;
//     int score=0;
//     Boolean flag = true;
//     public void setnum(int x){
//         rndnum = x;
//     }
//     public Boolean numpos(int x){
//         gesnum = x;
//         if(gesnum<rndnum){
//             System.out.println("It is smaller than the number.");
//             score++;
//             return flag = true;
//         }
//         else if(gesnum>rndnum){
//             System.out.println("It is larger than the number.");
//             score++;
//             return flag = true;
//         }
//         else{
//             System.out.println("Congratulations, you guessed the correct number!");
//             score++;
//             System.out.println("Your score is : "+score);
//             return flag = false;
//         }
//     }
// }

// public class ex3_gesnum {
//     public static void main(String[] args) {
        
// Scanner sc = new Scanner(System.in);
// System.out.println("Enter a number:");
// int y = sc.nextInt();
// game g1 = new game();
// g1.setnum(y);
// while(g1.flag !=false){
//     System.out.println("Guess the number:"); 
//     int x = sc.nextInt();
//     g1.numpos(x);
// }
//     }
// }
