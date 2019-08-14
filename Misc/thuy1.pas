var m: longint;
    n, i, ans: integer;
begin
    writeln('Nhap do dai cua day so: ');
    readln(n);
    writeln('Nhap day so: ');
    for i := 1 to n do
    begin
        read(m);
        if (m mod 3 = 0) then ans := ans + 1;
    end;
    writeln('Ket qua la: ', ans);
    readln;
end.
