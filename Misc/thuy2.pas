var a: array[1..1000]  of char;
    n, i: integer;
begin
    writeln('Nhap do dai cua day ki tu: ');
    readln(n);
    writeln('Nhap day ki tu: ');
    for i:=1 to n do
    begin
      read(a[i]);
    end;
    writeln('Ket qua la: ');
    for i:= 1 to n do
    begin
      if ((a[i] >= 'a') and (a[i] <= 'z')) then  a[i] := chr(ord(a[i])-32);
      write(a[i]);
    end;
    readln;
end.
