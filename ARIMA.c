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

