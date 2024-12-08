#include <studio.h>
#define MAX 100

int main() {
	int n = 0;
	int choice, temp, value, number; 
	int arr[100];
	do {
		printf("\nMENU\n");
		printf("1. Nhap so phan tu va gia tri trong mang\n");
		printf("2. Gan tri cac phan tu trong mang\n");
		printf("3. Dem so luong so hoan hao\n");
		printf("4. Dem so luong so nguyen to\n");
		printf("5. Tim gia tri lon thu 2 (khong sap xep)\n");
		printf("6. Tim gia tri nho thu 2 (khong sap xep)\n");
		printf("7. Them phan tu tai vi tri\n");
		printf("8. Xoa phan tu tai vi tri\n");
		printf("9. Sap xep mang tang dan\n");
		printf("10. Sap xep mang giam dan\n");
		printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
		printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
		printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
		printf("14. Dao nguoc mang\n");
		printf("15. Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("So phan tu co trong mang la: ");
				scanf("%d", &n);
				printf("Gia tri co trong mang la: ");
				for (int i = 0; i < n; i++) {
					printf("Phan tu %d", i + 1);
					scanf("%d", &arr[i]);
				}
				break;
			case 2:
				printf("Gia tri phan tu trong mang la: ");
				for (int i = 0; i < n; i++) {
					printf("%d", arr[i]);
				}
				printf("\n");
				break;
			case 3:
				{
					int count = 0;
					for(int i = 0; i < n; i++) {
						int sum = 1;
						for (int j = 2; j * j <= arr[i]; j++) {
							if (arr[i] % j == 0) {
								sum += j;
								if (!(arr[i] / j == j)){
									sum += arr[i] / j;
								}
							}
						}
						if (sum == arr[i] && arr[i] >= 6) {
							count++;
							printf("%d", arr[i]);
						}
					}
				}
				printf("So so phan tu hoan hao la: %d\n", count);
				break;
			case 4:
				int count = 0;
				for (int i = 0; i < n; i++) {
					int prime = 0;
					for (int j = 2; j * j <= arr[i]; j++) {
						if(arr[i] % j == 0) {
							prime = 1;
							break;
						}
					}
					if (!prime && arr[i] >= 2) {
						++count;
					}
				}
				printf("So luong cac phan tu la so nguyen to la: %d\n", count);
				break;
			case 5:
				int max = arr[0], max2;
				for (int i = 0; i < n; ++i) {
					if (arr[i] > max) {
						max2 = max;
						max = arr[i];
					} else if (arr[i] > max2 && arr[i] != max) {
						max2 = arr[i];
					}	
				}
				printf("Phan tu lon thu hai trong mang la: %d\n", max2);
				break;
			case 6:
				int min = arr[0], min2;
				min2 = (arr[0] < arr[1] ? arr[1] : arr[0]);
				for (int i = 1; i < n; ++i) {
					if (arr[i] < min) {
						min2 = min;
						min = arr[i];
					} else if (arr[i] < min2 && arr[i] != min) {
						min2 = arr[i]
					}
				}
				printf("Phan tu nho thu hai trong mang la: %d\n", min2);
				break;
			case 7:
				int number, value;
				printf("Nhap gia tri can them: ");
				scanf("%d", &value);
				printf("Nhap vi tri can them: ");
				scanf("%d", &number);
				if (number > n) {
					arr[number - 1] = value;
					n = number;
				} else {
					for (int i = n; i >= number; --i) {
						arr[i] = arr[i - 1];
					}
					arr[number - 1] = value;
					n++;
				}
				break;
			case 8:
				int number;
				printf("Nhap vi tri can xoa: ");
				scanf("%d", &number);
				for (int i = number - 1; i < n - 1; ++i) {
					arr[i] = arr[i + 1];
				}
				--n;
				break;
			case 9:
				for (int i = 1; i < n; ++i) {
					int temp = arr[i], j = i - 1;
					while(j >= 0 && arr[j] > temp) {
						arr[j + 1] = arr[j];
						--j;
					}
					arr[j + 1] = temp;
				}
				break;
			case 10:
				for (int i = 1; i < n; ++i) {
					int temp = arr[i], j = i - 1;
					while(j >= 0 && arr[j] < temp) {
						arr[j + 1] = arr[j];
						--j;
					}
					arr[j + 1] = temp;
				}
				break;
			case 11:
				int value;
				printf("Nhap phan tu can tim: ");
				scanf("%d", &value);
				int found = 0;
				int l = 0; r = n - 1;
				while(l <= r) {
					int m = l + r;
					if(arr[m] == value) {
						printf("Gia tri %d ton tai trong mang\n", value);
						found = 1;
						break;
					} else if (arr[m] < value) {
						l = m + 1;
					} else {
						r = m - 1;
					}
					}
					if (!found) {
						printf("Gia tri %d khong ton tai trong mang\n", value);
					}
					break;
			case 12:
					int new = n;
		            for(int i = 0; i < new; ++i){
					 for(int j = i + 1; j< new;++j ){
					 if(a[i] == a[j]) {
				  	  for(int k = j; k < new - 1; ++k) {
				  		a[k] = a[k+1];
					}
					new--;
					j--;
				} 
			   }
			} 
			n = new;
            break;
			case 13:
				{
        	int odd[n], even[n];
			
			int j=0,k=0;
			for(int i=0;i<n;++i)
			{
				if(a[i]%2==0)
				{
					even[j++]=a[i];
				}
				else
					odd[k++]=a[i];
			}
			
			for(int i=1;i<j;++i)
        	{
        		int tmp=even[i], p=i-1;
        		while(p>=0 && even[p]>tmp)
        		{
					even[p+1]=even[p];
					--p;
				}
				even[p+1]=tmp;
			}
			
			for(int i=1;i<k;++i)
        	{
        		int tmp=odd[i], p=i-1;
        		while(p>=0 && odd[p]>tmp)
        		{
					odd[p+1]=odd[p];
					--p;
				}
				odd[p+1]=tmp;
			}
			
			for(int i=0;i<j;++i)
			{
				a[i]=even[i];
			}
			for(int i=0;i<k;++i)
			{
				a[j+i]=odd[i];
			}
        }
        break;
            case 14:
        	for(int i=0;i<n/2;++i)
			{
				int tmp=a[i];
				a[i]=a[n-i-1];
				a[n-i-1]=tmp;	
			}
			break; 
				}
			default:
				printf("Lua chon khong hop li. Chon lai\n");
		} 
	} while (choice != 15);
	
	return 0;
} 
