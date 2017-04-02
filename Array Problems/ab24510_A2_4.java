import java.util.Scanner;
class Matrix{
	static int count=0;
	int M;
	int N;
	Matrix(int m,int n)
	{
		M=m;
		N=n;
	}
	void creatMatrix(int arr[][]){
	Scanner sc=new Scanner(System.in);
	for(int i=0;i<M;i++){
			for(int j=0;j<N;j++)
			{
				arr[i][j]=sc.nextInt();
			}
		}
	}
	void Display(int arr[][])
	{
		for(int x[]:arr)
		{
			for(int a:x)
				System.out.print(a+"  ");
			System.out.println();
		}
	}
	void Spiral(int arr[][],int x,int y)
	{
		for(int j=y;j<N-x;j++)
		{	if(count>=M*N)
				break;
			System.out.print(arr[x][j]+"  ");
			count++;
		}
		for(int j=x+1;j<M-y;j++)
		{	if(count>=M*N)
				break;;
			System.out.print(arr[j][N-x-1]+"  ");	
			count++;
		}
		for(int j=N-y-2;j>=x;j--)
		{	if(count>=M*N)
				break;
			System.out.print(arr[M-x-1][j]+"  ");	
			count++;
		}
		for(int j=M-x-2;j>y;j--)
		{	if(count>=M*N)
				return;
			System.out.print(arr[j][x]+"  ");	
			count++;
		}
		
	}
}
class ab24510_A2_4{
	public static void main(String arg[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Number of Rows(M) & Column(N) of Matrix");
		int m=sc.nextInt();
		int n=sc.nextInt();
		Matrix mat=new Matrix(m,n);
		int arr[][]=new int[m][n];
		System.out.println("\nEnter All the Elements");
		mat.creatMatrix(arr);
		System.out.println("Matrix Represented as:");
		mat.Display(arr);
		System.out.println("\nElements in Spiral order are :\n");
		for(int i=0;;i++){
			if(mat.count<m*n)
		mat.Spiral(arr,i,i);
			else 
				break;
		}
	}
}