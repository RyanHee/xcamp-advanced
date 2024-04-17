import java.util.HashSet;
import java.util.Scanner;

public class Territory {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n, m;
        n=sc.nextInt();
        m=sc.nextInt();
        sc.nextLine();
        char[][]map = new char[m][n];
        for (int i=0;i<m;i++){
            String s = sc.nextLine();
            map[i]=s.toCharArray();
        }

        int x=0;
        int y=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                //System.out.println(c);
                if (map[i][j] == '@'){
                    x=i;
                    y=j;
                    break;
                }

            }

        }
        int result=solve(x, y, map, new HashSet<>());
        System.out.println(result);



    }

    public static int solve(int x, int y, char[][]map, HashSet<Integer> visited){
        if (x<0){
            return 0;
        }
        if (y<0){
            return 0;
        }
        if (x==map.length){
            return 0;
        }
        if (y==map[0].length){
            return 0;
        }
        if (map[x][y]=='#'){
            return 0;
        }
        int pos=x*100+y;
        if (visited.contains(pos)) {
            return 0;
        }
        visited.add(pos);
        return 1+solve(x-1, y, map, visited)
                +solve(x+1, y, map, visited)
                +solve(x, y-1, map, visited)
                +solve(x, y+1, map, visited);
        //return result;
    }
}