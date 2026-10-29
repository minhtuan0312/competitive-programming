# ~/code/cp

```
cp/
├── codeforces/  cses/  marisaoj/  lqdoj/  atcoder/  vnoi/  spoj/
│   └── <tên-bài>/main.cpp  (+ 1.in 1.out, gen.cpp, brute.cpp nếu cần)
├── hsg/                đề HSG theo năm/tỉnh
├── 28tech/  youkn0wwho/   bài theo khoá học / chủ đề
├── notebooks/          ghi chú theo chủ đề (Greedy, Sparse Table, ...)
├── icpc/
│   ├── regionals/      đề ICPC cũ, luyện theo đội (cpnew icpc ...)
│   └── notebook/kactl  team notebook KACTL để tham khảo/in
└── shared/
    ├── templates/      main.cpp (multi-test, cho CF) · single.cpp (các OJ khác)
    ├── debug.h         dbg(x, v, mp) -> stderr, chỉ bật khi -DLOCAL
    └── algorithms/ data-structures/ snippets/   thư viện CỦA BẠN
```

## Lệnh (Fish trong Kitty)

| Lệnh | Việc |
|---|---|
| `cpnew cf 2051A` | tạo `codeforces/2051A/main.cpp` từ template, cd vào, mở VS Code tại dòng cần code |
| `cpnew cses 1068 Weird Algorithm` | → `cses/1068-Weird-Algorithm/` (tự bỏ dấu, dấu cách → `-`) |
| `cfnew`, `csesnew`, `marisanew`, `lqnew`, `icpcnew` | viết tắt của `cpnew <nền tảng>` |
| `cpcontest cf 2051 G` | tạo `codeforces/2051/{A..G}/main.cpp`, mở cả contest |
| `cpc`, `cf`, `cpg cses` | cd nhanh |
| `cprun` | biên dịch (-O2, có PCH nên ~0.5s) + chạy mọi `*.in`, so với `*.out`/`*.ans` → AC/WA/TLE/RE |
| `cprun -d` (`cpd`) | bản debug: AddressSanitizer + UBSan + `_GLIBCXX_DEBUG` (bắt tràn mảng, tràn số, UB) |
| `cpadd` | copy input mẫu trên web → `cpadd` → copy output → Enter ⇒ tạo `N.in`/`N.out` |
| `stress [N]` | so `main.cpp` với `brute.cpp` trên test từ `gen.cpp <seed>`; sai thì lưu `fail.in` |

Trong VS Code: **Ctrl+Alt+N** (Code Runner) = `cprun`. Extension **CPH** + tiện ích

## Quy trình mỗi bài

1. **Đọc kỹ đề + ràng buộc trước khi code.** Từ `n` suy ra độ phức tạp:
   n ≤ 20 → 2ⁿ · n ≤ 500 → n³ · n ≤ 5000 → n² · n ≤ 2·10⁵ → n log n · n ≤ 10⁷ → O(n).
2. Viết ý tưởng + độ phức tạp vào comment đầu `main.cpp` (2–3 dòng). Không rõ thì chưa code.
3. Code → `cprun` cho test mẫu → **tự nghĩ test biên** (n=1, max n, toàn số âm, toàn bằng nhau) rồi `cpadd`.
4. WA mà không thấy lỗi → `cprun -d` trước (UB/tràn mảng chiếm phần lớn lỗi "vô lý"),
   sau đó viết `brute.cpp` + `gen.cpp` và chạy `stress`. Đừng nộp mò.
5. Checklist trước khi nộp: `long long` khi tích/tổng > 2·10⁹ · reset mảng/biến giữa các test ·
   đúng chế độ multi-test · bỏ `dbg` không ảnh hưởng (đã tự tắt khi không có `-DLOCAL`).
6. **Upsolve**: sau contest giải tiếp mọi bài ≤ (bài cuối làm được + 1). Đọc editorial chỉ sau ≥ 30–45 phút bí,
   rồi tự code lại không nhìn. Bài nào học được kỹ thuật mới → chép phần cốt lõi vào `shared/` (thư viện riêng).
7. `git add -A && git commit -m "cf 2051A"` sau mỗi buổi - lịch sử luyện tập chính là nhật ký tiến bộ.

## Lộ trình gợi ý

- **CSES Problem Set** làm hết theo chủ đề (nền tảng chuẩn), song song **Codeforces** contest Div 2/3 đều đặn (thi live, không bỏ).
- Luyện **virtual contest** đề ICPC cũ (Vietnam National/Regional, Asia) theo đội 3 người, **1 máy**, 5 giờ -
  ICPC chỉ có 1 bàn phím nên phải luyện chia việc, đọc đề song song, code trên giấy khi máy bận.
- Tự xây **team notebook ≤ 25 trang** (dựa trên KACTL, chỉ giữ thứ đội hiểu và đã dùng). Mọi đoạn trong notebook phải được test qua bài thật.
- Luyện gõ không cần internet/AI: đi thi không có autocomplete thông minh, nên thỉnh thoảng code bằng nvim/không extension.
