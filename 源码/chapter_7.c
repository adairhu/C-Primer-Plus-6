//7.1
#include <stdio.h>
#define STOP '#'
#define BLANK ' '

int main(void)
{
    char ch;
    long n_chars = 0L;
    int n_blanks = 0;
    int n_lines = 0;

    printf("Enter text to be analyzed (# to quit):\n");
    while((ch = getchar()) != '\#'){
        if(ch == BLANK)
            n_blanks++;
        else if(ch == '\n')
            n_lines++;
        else
            n_chars++;
    }
    printf("blanks: %d, lines: %d, other chars: %ld\n",
            n_blanks, n_lines, n_chars);

    return 0;
}


//7.2
#include <stdio.h>
#define STOP '#'
#define SIZE 8

int main(void)
{
    char ch;
    long count = 0L;

    printf("Enter text to be analyzed (# to quit):\n");
    while((ch = getchar()) != STOP){
        if(ch == '\n')
            break;
        count++;
        printf("%c:%-5d", ch, ch);
        if(count % SIZE == 0)
            printf("\n");
    }
    printf("\nBey");

    return 0;
}


//7.3
#include <stdio.h>
#define STOP 0

int main(void)
{
    int num;
    int ct_even = 0, ct_odd = 0;
    float sum_even = 0, sum_odd = 0;
    float mean_even, mean_odd;

    printf("Enter integer to be analyzed: ");
    // while(scanf("%d", &num) == 1){
    //     if(0 == num) 
    //         break;
    while(scanf("%d", &num) == 1 && num != 0){
        if(num % 2 == 0)
        {
            ct_even++;
            sum_even += num;
        }
        else
        {
            ct_odd++;
            sum_odd += num;
        }
        printf("please enter the next number(0 to quit): ");
    }
    if(ct_even > 0)
        mean_even = sum_even / (float)ct_even;
    printf("Number of even：%d， Mean：%g\n", ct_even, ct_even ? mean_even : 0);
    if(ct_odd > 0)
        mean_odd = sum_odd / (float)ct_odd;
    printf("Number of odd: %d, Mean: %g\n", ct_odd, ct_odd ? mean_odd : 0);

    printf("Done");

    return 0;
}


// 7.4
#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch;
    int count = 0;
    printf("Enter text:\n");
    while((ch = getchar()) != STOP){
        if(ch == '.'){
            putchar('!');
            count++;
        }
        else if(ch == '!'){
            printf("!!");
            count++;
        }
        else
        {
            putchar(ch);
        }
        
    }
    printf("\nExchanged %d times.\n", count);

    return 0;
}


// 7.5
#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch;
    int count = 0;
    printf("Enter text:\n");
    while((ch = getchar()) != STOP){
        switch(ch){
            case '.': 
                putchar('!');
                count++;
                 break;
            case '!':
                printf("!!");
                count++;
                break;
            default:
                putchar(ch);
        }
        
    }
    printf("\nExchanged %d times.\n", count);

    return 0;
}


// 7.6 -- 法1
#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch, pre_ch;
    int count = 0;
    printf("Enter text(# to quit):\n");
    while((ch = getchar()) != STOP){
        // if(ch == 'i'){
        //     if(pre_ch == 'e')
        //         count++;
        // }
        if(ch == 'i' && pre_ch == 'e')
            count++;
            
        pre_ch = ch;
    }
    printf("\n\"ei\" appeared %d times.", count);

    return 0;
}


// 7.6 -- 法2
#include <stdio.h>
#include <stdbool.h>
#define STOP '#'

int main(void)
{
    char ch;
    int count = 0;
    bool in_ei = false;
    printf("Enter text(# to quit):\n");
    while((ch = getchar()) != STOP){
        if(ch == 'e')
            in_ei = true;
        else if(ch == 'i' && in_ei){
            count++;
            in_ei = false;
        }        
    }
    printf("\n\"ei\" appeared %d times.", count);

    return 0;
}


// 7.7
#include <stdio.h>
#define SALARY_PER_HOUR 10
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    double hours;
    double gross, tax, net;

    printf("Enter your work hours in a week: ");
    scanf("%lf", &hours);
    if(hours > TIME_BASE)
        hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
    gross = hours * SALARY_PER_HOUR;
    if(gross < BREAK1)
        tax = gross * RATE1;
    else if(gross < BREAK2)
        tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
    else
        tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
            + (gross - BREAK2) * RATE3;
    net = gross - tax;
    printf("Gross: %.2lf, tax: %.2lf, net: %.2lf", gross, tax, net);

    return 0;
}


// 7.8 -- 型1：只计算1次正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    int num;
    bool is_1_to_5 = false; // 这里的标志位必须为false,以防用户一开始就输入非数字
    double pay_rate;
    double hours;
    double gross, tax, net;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
    //读取正确输入，直达是1-5之间才退出循环
    while(scanf("%d", &num) == 1){
        is_1_to_5 = true;   //每次循环标志位置为true
        switch(num){
            case 1: pay_rate = PAY_RATE1; break;
            case 2: pay_rate = PAY_RATE2; break;
            case 3: pay_rate = PAY_RATE3; break;
            case 4: pay_rate = PAY_RATE4; break;
            case 5: break;
            default: 
                printf("\nPlease enter the right number!\n");
                printf("*****************************************************************\n");
                printf("Enter the number corresponding to the desired pay rate or action:\n");
                printf("1) $8.75/hr         2) $9.33/hr\n");
                printf("3) $10.00/hr        4) $11.20/hr\n");
                printf("5) quit\n");
                printf("******************************************************************\n");
                is_1_to_5 = false;
        }
        // 1-5标志位，是1-5则break跳出
        if(is_1_to_5)
            break;
        //否则，将标志位复位至true,进行下一次while循环  
        //is_1_to_5 = true;   因为进入循环第一句就是将其置为true,故这里可以省略       
    }
    if(is_1_to_5){
        printf("Enter your work hours in a week: ");
        scanf("%lf", &hours);
        if(hours > TIME_BASE)
            hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
        gross = hours * pay_rate;
        if(gross < BREAK1)
            tax = gross * RATE1;
        else if(gross < BREAK2)
            tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
        else
            tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
                + (gross - BREAK2) * RATE3;
        net = gross - tax;
        printf("Gross: %.2lf, tax: %.2lf, net: %.2lf", gross, tax, net);
    }       
 
    return 0;
}



// 7.8 -- 型2（法1）：循环计算正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    int num;
    bool is_1_to_5 = false; // 这里的标志位必须为false,以防用户一开始就输入非数字
    double pay_rate;
    double hours;
    double gross, tax, net;
    
    while(1){
        printf("\n*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr         2) $9.33/hr\n");
        printf("3) $10.00/hr        4) $11.20/hr\n");
        printf("5) quit\n");
        printf("******************************************************************\n");
        //读取正确输入，直达是1-5之间才退出循环
        while(scanf("%d", &num) == 1){  //经过scanf筛选，进入循环的肯定是数字，排除了非数字字符
            is_1_to_5 = true;   //每次循环标志位置为true
            switch(num){
                case 1: pay_rate = PAY_RATE1; break;
                case 2: pay_rate = PAY_RATE2; break;
                case 3: pay_rate = PAY_RATE3; break;
                case 4: pay_rate = PAY_RATE4; break;
                case 5: break;
                default: 
                    printf("\nPlease enter the right number!\n");
                    printf("*****************************************************************\n");
                    printf("Enter the number corresponding to the desired pay rate or action:\n");
                    printf("1) $8.75/hr         2) $9.33/hr\n");
                    printf("3) $10.00/hr        4) $11.20/hr\n");
                    printf("5) quit\n");
                    printf("******************************************************************\n");
                    is_1_to_5 = false;
            }
            // 1-5标志位，是1-5则break跳出
            if(is_1_to_5)
                break;
            //否则，将标志位复位至true,进行下一次while循环  
            //is_1_to_5 = true;   因为进入循环第一句就是将其置为true,故这里可以省略       
        }
        if(is_1_to_5 && num != 5){  //从数字里再筛选出1-4，排除了5
            is_1_to_5 = false;  //一定要将标志位设为最初定义时的状态，以便进行新一轮外侧循环
            printf("Enter your work hours in a week: ");
            scanf("%lf", &hours);
            if(hours > TIME_BASE)
                hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
            gross = hours * pay_rate;
            if(gross < BREAK1)
                tax = gross * RATE1;
            else if(gross < BREAK2)
                tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
            else
                tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
                    + (gross - BREAK2) * RATE3;
            net = gross - tax;
            printf("Gross: %.2lf, tax: %.2lf, net: %.2lf\n", gross, tax, net);
        }
        else
            break;       
    }

    return 0;
}


// 7.8 -- 型2 (法2)：循环计算正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    int num;
    double pay_rate;
    double hours;
    double gross, tax, net;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
  
    while(scanf("%d", &num) == 1){
        switch(num){
            case 1: pay_rate = PAY_RATE1; break;
            case 2: pay_rate = PAY_RATE2; break;
            case 3: pay_rate = PAY_RATE3; break;
            case 4: pay_rate = PAY_RATE4; break;
        }
        if(num > 0 && num < 5){
            printf("Enter your work hours in a week: ");
            scanf("%lf", &hours);
            if(hours > TIME_BASE)
                hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
            gross = hours * pay_rate;
            if(gross < BREAK1)
                tax = gross * RATE1;
            else if(gross < BREAK2)
                tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
            else
                tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
                    + (gross - BREAK2) * RATE3;
            net = gross - tax;
            printf("Gross: %.2lf, tax: %.2lf, net: %.2lf\n", gross, tax, net);

            printf("*****************************************************************\n");
            printf("Enter the number corresponding to the desired pay rate or action:\n");
            printf("1) $8.75/hr         2) $9.33/hr\n");
            printf("3) $10.00/hr        4) $11.20/hr\n");
            printf("5) quit\n");
            printf("******************************************************************\n");
        }
        else if(5 == num)
            break;
        else
        {
            printf("\nPlease enter the right number!\n");

            printf("*****************************************************************\n");
            printf("Enter the number corresponding to the desired pay rate or action:\n");
            printf("1) $8.75/hr         2) $9.33/hr\n");
            printf("3) $10.00/hr        4) $11.20/hr\n");
            printf("5) quit\n");
            printf("******************************************************************\n");
        }
        
    }
 
    return 0;
}


// 7.8 -- 型2 (法3) 使用goto更方便
#include <stdio.h>
#include <stdbool.h>
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    int num;
    double pay_rate;
    double hours;
    double gross, tax, net;

    printpart:   
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
  
    while(scanf("%d", &num) == 1){
        switch(num){
            case 1: pay_rate = PAY_RATE1; break;
            case 2: pay_rate = PAY_RATE2; break;
            case 3: pay_rate = PAY_RATE3; break;
            case 4: pay_rate = PAY_RATE4; break;
            case 5: return 0; //这里用break不行，因为此处在两个包围里：switch、while,break只能跳出switch,而我们要直接跳出两层包围
            default: goto printpart;
        }      
        printf("Enter your work hours in a week: ");
        scanf("%lf", &hours);
        if(hours > TIME_BASE)
            hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
        gross = hours * pay_rate;
        if(gross < BREAK1)
            tax = gross * RATE1;
        else if(gross < BREAK2)
            tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
        else
            tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
                + (gross - BREAK2) * RATE3;
        net = gross - tax;
        printf("Gross: %.2lf, tax: %.2lf, net: %.2lf\n", gross, tax, net); 
        goto printpart;       
    }
 
    return 0;
}


// 7.9
#include <stdbool.h>

int main(void)
{
    int num;
    int prime;
    bool is_prime = true;

    printf("Enter a integer: ");
    scanf("%d", &num);
    // for(prime = 1; prime <= num; prime++){
    //     is_prime = true;   //千万千万要记住：进入下一次循环之前必须将标志位复位！
    for(prime = 1; is_prime = true; prime <= num; prime++)  //初始化可以合到一起
        for(int j = 2; j * j <= prime; j++){
            if(prime % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime)
            printf("%3d", prime);        
    }

    return 0;
}



// 7.10
#include <stdio.h>
#define BASEPAY1 17850
#define BASEPAY2 23900
#define BASEPAY3 29750
#define BASEPAY4 14875
#define RATE1 0.15
#define RATE2 0.28

int main(void)
{
    int type;
    double income;
    double basepay;
    double tax;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired tax type or action:\n");
    printf("1) 单身             2) 户主\n");
    printf("3) 已婚，共有       4) 已婚，离异\n");
    printf("5) quit\n");
    printf("******************************************************************\n");

    while(scanf("%d", &type) == 1){
        switch(type){
            case 1: basepay = BASEPAY1; break;
            case 2: basepay = BASEPAY2; break;
            case 3: basepay = BASEPAY3; break;
            case 4: basepay = BASEPAY4; break;    
        }
        if(type > 0 && type < 5){
            printf("Enter your income: ");
            scanf("%lf", &income);
            printf("\n");
            if(income <= basepay)
                tax = income * RATE1;
            else
                tax = BASEPAY1 * RATE1 + (income - BASEPAY1) * RATE2;
            printf("Your tax is %.2lf: ", tax);

            printf("\n*****************************************************************\n");
            printf("Enter the number corresponding to the desired tax type or action:\n");
            printf("1) 单身             2) 户主\n");
            printf("3) 已婚，共有       4) 已婚，离异\n");
            printf("5) quit\n");
            printf("******************************************************************\n"); 
        }
        else if(5 == type)
            break;
        else{
            printf("Please enter right number\n");

            printf("\n*****************************************************************\n");
            printf("Enter the number corresponding to the desired tax type or action:\n");
            printf("1) 单身             2) 户主\n");
            printf("3) 已婚，共有       4) 已婚，离异\n");
            printf("5) quit\n");
            printf("******************************************************************\n");                  
        }
    }
    return 0;
}


// 7.11
#include <stdio.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define BASE_PAY 100
#define DISCOUNT_RATE 0.05
#define BASE_WEIGHT1 5
#define BASE_WEIGHT2 20
#define BASE_SHIPPING1 6.5
#define BASE_SHIPPING2 14
#define ADJUST_SHIPPING 0.5

int main(void)
{
    char ch;
    double weight, total_weight,  artichoke_weight = 0, beet_weight = 0, carrot_weight = 0;
    double vegetable_pay, discount, shipping_pay, total_pay;

    printf("*************************************************************************\n");
    printf("Enter Enter the letter corresponding to the desired vegetables or action:\n");
    printf("a 洋蓟             b 甜菜\n");
    printf("c 胡萝ト           q 退出\n");
    printf("*************************************************************************\n");
    //菜单
    while((ch = getchar()) != 'q'){
        if(ch == '\n')  //消除前面输入a/b/c/q后按的回车键，以便后面获得干净的输入值。又因为后面是scanf()函数，故这里的代码可以省略。如果后面是getchar()函数必须要这段代码。
             continue;
        printf("Enter again weight of the vegetable you want: ");
        scanf("%lf", &weight);
        while(getchar() != '\n')    //滤掉输入重量后面的所有字符
            continue;
        switch(ch){
            case 'a': artichoke_weight += weight; break;
            case 'b': beet_weight += weight; break;
            case 'c': carrot_weight += weight; break;
            default: printf("%c is not a valid choice.\n", ch);
        }
        printf("\nYou have ordered:\n");
        printf("洋蓟: %.1lf 磅， 甜菜: %.1lf 磅，胡萝卜: %.1lf 磅\n",
                artichoke_weight, beet_weight, carrot_weight);
        
        printf("\n***********************************************************************\n");
        printf("Enter Enter the letter corresponding to the desired vegetables or action:\n");
        printf("a 洋蓟             b 甜菜\n");
        printf("c 胡萝ト           q 退出\n");
        printf("*************************************************************************\n");
    }
    //开始计算蔬菜费用
    vegetable_pay = artichoke_weight * ARTICHOKE + beet_weight * BEET + carrot_weight * CARROT;
    if(vegetable_pay >= BASE_PAY){
        discount = vegetable_pay * DISCOUNT_RATE;
        //vegetable_pay -= discount;
    }
    else
        discount = 0;        
    //计算运费
    total_weight = artichoke_weight + beet_weight + carrot_weight;
    if(total_weight <= BASE_WEIGHT1)
        shipping_pay = BASE_SHIPPING1;
    else if(total_weight > 5 && total_weight < 20)
        shipping_pay = BASE_SHIPPING2;
    else
       shipping_pay = BASE_SHIPPING2 + (total_weight - BASE_WEIGHT2) * ADJUST_SHIPPING;
    //计算费用总额
    total_pay = vegetable_pay - discount + shipping_pay;
    //输出
    printf("蔬菜种类      洋蓟      甜菜      胡萝卜\n");
    printf("售价          2.05      1.15       1.09\n");
    printf("订购重量(磅)  %g        %g        %g\n",
            artichoke_weight, beet_weight, carrot_weight);
    printf("\n蔬菜费用: %.2lf, 折扣: %.2lf, 运费和包装费: %.2lf\n总费用: %.2lf\n",
            vegetable_pay, discount, shipping_pay, total_pay);
    printf("welcome again!");
}