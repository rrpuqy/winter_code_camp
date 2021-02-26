import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
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

        // ================= 代码实现开始 =================

        // 初始化函数，在操作开始前会调用一次
        void init(int n) {
        }

        // x 是编号，范围为 1 到 n
        // 若成功操作，返回 true，否则返回 false
        boolean split_succ(int x) {
            return true;
        }

        // x 是编号，范围为 1 到 n
        // 若成功操作，返回 true，否则返回 false
        boolean split_prev(int x) {
            return true;
        }

        // x, y 是编号，范围为 1 到 n
        // 若成功操作，返回 true，否则返回 false
        boolean link(int x, int y) {
            return true;
        }

        // x 是编号，范围为 1 到 n
        // 返回遍历得到的序列
        List<Integer> visit_succ(int x) {
            return new ArrayList<>();
        }

        // x 是编号，范围为 1 到 n
        // 返回遍历得到的序列
        List<Integer> visit_prev(int x) {
            return new ArrayList<>();
        }

        // ================= 代码实现结束 =================

        void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            init(n);
            for (int i = 0; i < m; ++i) {
                String op = in.next();
                int x = in.nextInt();
                if (op.equals("split_succ")) {
                    out.println(split_succ(x) ? "yes" : "no");
                } else if (op.equals("split_prev")) {
                    out.println(split_prev(x) ? "yes" : "no");
                } else if (op.equals("link")) {
                    int y = in.nextInt();
                    out.println(link(x, y) ? "yes" : "no");
                } else if (op.equals("visit_succ")) {
                    List<Integer> ans = visit_succ(x);
                    for (Integer t : ans) {
                        out.print(t);
                        out.print(' ');
                    }
                    out.println();
                } else {
                    List<Integer> ans = visit_prev(x);
                    for (Integer t : ans) {
                        out.print(t);
                        out.print(' ');
                    }
                    out.println();
                }
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