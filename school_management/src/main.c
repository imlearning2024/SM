#include "../include/school.h"

int main() {
  int option;

  while (1) {
    printf("\n------- School Management ------------");
    printf("\n1. Admission");
    printf("\n2. Admission Cancellation");
    printf("\n3. Admission Enquiry");
    printf("\n4. Detail");
    printf("\n5. Fee Payment");
    printf("\n6. Exit");

    printf("\nChoose option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      admsn();
      break;
    case 2:
      admsn_cancel();
      break;
    case 3:
      admsn_enq();
      break;
    case 4:
      detail();
      break;
    case 5:
      fee_payment();
      break;
    case 6:
      return 0;
    default:
      printf("Invalid Option\n");
      break;
    }
  }
}
