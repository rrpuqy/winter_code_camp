import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
    

    static class Task {
        
        // 二叉树的节点，包含左右孩子的编号（在数组中的下标），编号范围为 0 到 n-1，若编号为 -1，表示空
        class Node {
            int l; // 表示左节点的编号
            int r; // 表示右节点的编号
            Node(int l, int r) {
                this.l = l;
                this.r = r;
            }
        }

        // ================= 代码实现开始 =================

        // n：二叉树节点个数
        // a：二叉树 a 的节点数组，大小为 n
        // b：二叉树 b 的节点数组，大小为 n
        // 返回值：若二叉树 a 与 b 相等，则返回真，否则返回假
        // 提示：
        // 解释一下节点数组的意思，由于节点的编号在 0 到 n-1 的范围内
        // 因此可以将这 n 个节点存储到一个数组里，那么二叉树 a 中编号
        // 为 i 的节点就是 a[i]，其左孩子编号为 a[i].l，右孩子编号为 a[i].r
        // a[i] 的左孩子为 a[a[i].l]，右孩子为 a[a[i].r]
        // 一定要把编号与节点区分开来，同时还要注意编号为 -1 的情况，此时该孩子
        // 为空，不能用 -1 去作为数组下标噢，越界了。
        boolean get_answer(int n, Node[] a, Node[] b) {
            return true;
        }

        // ================= 代码实现结束 =================
        
        void solve(InputReader in, PrintWriter out) {
            int T = in.nextInt();
            while (T-- > 0) {
                int n = in.nextInt();
                Node[] a = new Node[n];
                Node[] b = new Node[n];
                
                for (int i = 0; i < n; i++) {
                    int l = in.nextInt();
                    int r = in.nextInt();
                    a[i] = new Node(l, r);
                }
                for (int i = 0; i < n; i++) {
                    int l = in.nextInt();
                    int r = in.nextInt();
                    b[i] = new Node(l, r);
                }

                out.println(get_answer(n, a, b) ? "yes" : "no");
            }
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        private InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        private String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        private short nextShort() {
            return Short.parseShort(next());
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private long nextLong() {
            return Long.parseLong(next());
        }

        private float nextFloat() {
            return Float.parseFloat(next());
        }

        private double nextDouble() {
            return Double.parseDouble(next());
        }
    }

}
