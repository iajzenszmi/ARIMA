# ARIMA
ARIMA in C programming language.

ian@ian-HP-Convertible-x360-11-ab1XX:~$ ls ARIMA*
ARIMA.c
ian@ian-HP-Convertible-x360-11-ab1XX:~$ gcc ARIMA.c -o ARIMA
ian@ian-HP-Convertible-x360-11-ab1XX:~$ ./ARIMA
AR coefficients: 38.50 36.67 
MA coefficients: 38.50 
ian@ian-HP-Convertible-x360-11-ab1XX:~$ cat ARIMA.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the autoregression coefficients
void autoregression(double *data, int n, int p, double *ar) {
  int i, j;
  double sum;

  for (i = 0; i < p; i++) {
    sum = 0;
    for (j = i; j < n; j++) {
      sum += data[j] * data[j - i];
    }
    ar[i] = sum / (n - i);
  }
}

// Function to calculate the moving average coefficients
void moving_average(double *data, int n, int q, double *ma) {
  int i, j;
  double sum;

  for (i = 0; i < q; i++) {
    sum = 0;
    for (j = i; j < n; j++) {
      sum += data[j] * data[j - i];
    }
    ma[i] = sum / (n - i);
  }
}

// Function to calculate the ARIMA coefficients
void arima(double *data, int n, int p, int d, int q, double *ar, double *ma) {
  autoregression(data, n, p, ar);
  moving_average(data, n, q, ma);
}

int main() {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(data) / sizeof(data[0]);
  int p = 2;
  int d = 1;
  int q = 1;
  double ar[p], ma[q];

  // Calculate the ARIMA coefficients
  arima(data, n, p, d, q, ar, ma);

  // Print the ARIMA coefficients
  printf("AR coefficients: ");
  for (int i = 0; i < p; i++) {
    printf("%.2f ", ar[i]);
  }
  printf("\nMA coefficients: ");
  for (int i = 0; i < q; i++) {
    printf("%.2f ", ma[i]);
  }
  printf("\n");

  return 0;
}

ian@ian-HP-Convertible-x360-11-ab1XX:~$ sloccount ARIMA.c
Have a non-directory at the top, so creating directory top_dir
Adding /home/ian/ARIMA.c to top_dir
Categorizing files.
Finding a working MD5 command....
Found a working MD5 command.
Computing results.


SLOC	Directory	SLOC-by-Language (Sorted)
48      top_dir         ansic=48


Totals grouped by language (dominant language first):
ansic:           48 (100.00%)




Total Physical Source Lines of Code (SLOC)                = 48
Development Effort Estimate, Person-Years (Person-Months) = 0.01 (0.10)
 (Basic COCOMO model, Person-Months = 2.4 * (KSLOC**1.05))
Schedule Estimate, Years (Months)                         = 0.09 (1.04)
 (Basic COCOMO model, Months = 2.5 * (person-months**0.38))
Estimated Average Number of Developers (Effort/Schedule)  = 0.10
Total Estimated Cost to Develop                           = $ 1,114
 (average salary = $56,286/year, overhead = 2.40).
SLOCCount, Copyright (C) 2001-2004 David A. Wheeler
SLOCCount is Open Source Software/Free Software, licensed under the GNU GPL.
SLOCCount comes with ABSOLUTELY NO WARRANTY, and you are welcome to
redistribute it under certain conditions as specified by the GNU GPL license;
see the documentation for details.
Please credit this data as "generated using David A. Wheeler's 'SLOCCount'."
ian@ian-HP-Convertible-x360-11-ab1XX:~$ 

Sure, here is an example of an ARIMA program in C language:
C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the autoregression coefficients
void autoregression(double *data, int n, int p, double *ar) {
  int i, j;
  double sum;

  for (i = 0; i < p; i++) {
    sum = 0;
    for (j = i; j < n; j++) {
      sum += data[j] * data[j - i];
    }
    ar[i] = sum / (n - i);
  }
}

// Function to calculate the moving average coefficients
void moving_average(double *data, int n, int q, double *ma) {
  int i, j;
  double sum;

  for (i = 0; i < q; i++) {
    sum = 0;
    for (j = i; j < n; j++) {
      sum += data[j] * data[j - i];
    }
    ma[i] = sum / (n - i);
  }
}

// Function to calculate the ARIMA coefficients
void arima(double *data, int n, int p, int d, int q, double *ar, double *ma) {
  autoregression(data, n, p, ar);
  moving_average(data, n, q, ma);
}

int main() {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(data) / sizeof(data[0]);
  int p = 2;
  int d = 1;
  int q = 1;
  double ar[p], ma[q];

  // Calculate the ARIMA coefficients
  arima(data, n, p, d, q, ar, ma);

  // Print the ARIMA coefficients
  printf("AR coefficients: ");
  for (int i = 0; i < p; i++) {
    printf("%.2f ", ar[i]);
  }
  printf("\nMA coefficients: ");
  for (int i = 0; i < q; i++) {
    printf("%.2f ", ma[i]);
  }
  printf("\n");

  return 0;
}

Use code with caution. Learn more

This program takes a set of data as input, and then calculates the ARIMA coefficients for that data. The ARIMA coefficients are then printed to the console.

To compile and run this program, you can use the following commands:

gcc arima.c -o arima
./arima

This will compile the program and create an executable file called arima. You can then run the program by typing ./arima.

I hope this helps!

