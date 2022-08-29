
CREATE TABLE GiangVien(
MaGV char(4) NOT NULL,
HoTen nchar(30) NOT NULL,
DiaChi nvarchar(50) NOT NULL,
NgaySinh date NOT NULL,
CONSTRAINT KhoaChinhGiangVien PRIMARY KEY (MaGV)
)
CREATE TABLE DeTai(
MaDT char(4) NOT NULL,
TenDT nvarchar(50) NOT NULL,
Cap nchar(12) NOT NULL,
KinhPhi integer,
CONSTRAINT KhoaChinhDeTai PRIMARY KEY (MaDT)
)
CREATE TABLE ThamGia(
MaGV char(4) NOT NULL,
MaDT char(4) NOT NULL,
SoGio smallint,
CONSTRAINT KhoaChinhThamGia PRIMARY KEY (MaGV, MaDT),
CONSTRAINT KhoaNgoai1 FOREIGN KEY (MaGV) REFERENCES GiangVien (MaGV),
CONSTRAINT KhoaNgoai2 FOREIGN KEY (MaDT) REFERENCES DeTai (MaDT)
)

CREATE TABLE ThamGia(
MaGV char(4) NOT NULL,
MaDT char(4) NOT NULL,
SoGio smallint,
CONSTRAINT KhoaChinhThamGia PRIMARY KEY (MaGV, MaDT),
CONSTRAINT KhoaNgoai1 FOREIGN KEY (MaGV)
REFERENCES GiangVien (MaGV) on update cascade on delete cascade,
CONSTRAINT KhoaNgoai2 FOREIGN KEY (MaDT)
REFERENCES DeTai (MaDT) on update cascade on delete cascade
)

drop table ThamGia
drop table GiangVien
drop table DeTai

INSERT INTO GiangVien VALUES('GV01',N'Vũ Tuyết Trinh',N'Hoàng Mai, Hà Nội','1975/10/10'),
('GV02',N'Nguyễn Nhật Quang',N'Hai Bà Trưng, Hà Nội','1976/11/03'),
('GV03',N'Trần Đức Khánh',N'Đống Đa, Hà Nội','1977/06/04'),
('GV04',N'Nguyễn Hồng Phương',N'Tây Hồ, Hà Nội','1983/12/10'),
('GV05',N'Lê Thanh Hương',N'Hai Bà Trưng, Hà Nội','1976/10/10')

INSERT INTO DeTai VALUES ('DT01',N'Tính toán lưới',N'Nhà nước','700'),
('DT02',N'Phát hiện tri thức',N'Bộ','300'),
('DT03',N'Phân loại văn bản',N'Bộ','270'),
('DT04',N'Dịch tự động Anh Việt',N'Trường','30')

INSERT INTO ThamGia VALUES ('GV01','DT01','100'),
('GV01','DT02','80'),
('GV01','DT03','80'),
('GV02','DT01','120'),
('GV02','DT03','140'),
('GV03','DT03','150'),
('GV04','DT04','180')
--1.Đưa ra thông tin giảng viên có địa chỉ ở quận “Hai Bà Trưng”,
--sắp xếp theo thứ tự giảm dần của họ tên.
select * from GiangVien
where DiaChi LIKE N'%Hai Bà Trưng%'
order by HoTen
--2.Đưa ra danh sách gồm họ tên, địa chỉ, ngày sinh của giảng viên
--có tham gia vào đề tài “Tính toán lưới”.
select HoTen, DiaChi, NgaySinh from GiangVien gv, ThamGia tg, DeTai dt
where gv.MaGV = tg.MaGV AND tg.MaDT = dt.MaDT
AND TenDT LIKE N'%Tính toán lưới%'
select HoTen, DiaChi, NgaySinh
from GiangVien inner join ThamGia on GiangVien.MaGV = ThamGia.MaGV
inner join DeTai on ThamGia.MaDT = DeTai.MaDT
where TenDT LIKE N'%Tính toán lưới%'

select *
from GiangVien left join ThamGia on GiangVien.MaGV = ThamGia.MaGV
--3.Đưa ra danh sách gồm họ tên, địa chỉ, ngày sinh của giảng viên
--có tham gia vào đề tài “Phân loại văn bản” hoặc “Dịch tự động Anh Việt”.
select HoTen, DiaChi, NgaySinh from GiangVien gv, ThamGia tg, DeTai dt
where gv.MaGV = tg.MaGV AND tg.MaDT = dt.MaDT
AND (TenDT LIKE N'%Phân loại văn bản%' OR TenDT LIKE N'%Dịch tự động Anh Việt%')

select HoTen, DiaChi, NgaySinh
from GiangVien inner join ThamGia on GiangVien.MaGV = ThamGia.MaGV
inner join DeTai on ThamGia.MaDT = DeTai.MaDT
where TenDT LIKE N'%Phân loại văn bản%' OR TenDT LIKE N'%Dịch tự động Anh Việt%'
select HoTen, DiaChi, NgaySinh
from GiangVien inner join ThamGia on GiangVien.MaGV = ThamGia.MaGV
inner join DeTai on ThamGia.MaDT = DeTai.MaDT
where TenDT IN (N'Phân loại văn bản', N'Dịch tự động Anh Việt')

--4.Cho biết thông tin giảng viên tham gia ít nhất 2 đề tài.
select * from GiangVien
where MaGV IN(select MaGV from ThamGia
group by MaGV having count(MaDT)>=2)
select GiangVien.MaGV, HoTen, DiaChi, NgaySinh from GiangVien, ThamGia
where GiangVien.MaGV = ThamGia.MaGV
group by GiangVien.MaGV, HoTen, DiaChi, NgaySinh having count(MaDT)>=2

--5.Cho biết tên giảng viên tham gia nhiều đề tài nhất.
select HoTen from GiangVien
where MaGV in(select MaGV from ThamGia
group by MaGV having count(MaDT)>=ALL(select count(MaDT)
from ThamGia
group by MaGV))

select max(somaxdt)
from (select count(MaDT) as somaxdt
from ThamGia group by MaGV) table1

--6.Đề tài nào tốn ít kinh phí nhất?
select * from DeTai
where KinhPhi<=ALL(select KinhPhi from DeTai)
select * from DeTai
where KinhPhi =(select min(KinhPhi) from DeTai)

--7.Cho biết tên và ngày sinh của giảng viên sống ở quận Tây Hồ
--và tên các đề tài mà giảng viên này tham gia.
select HoTen, NgaySinh, TenDT
from GiangVien gv, ThamGia tg, DeTai dt
where gv.MaGV = tg.MaGV AND tg.MaDT = dt.MaDT
AND DiaChi LIKE N'%Tây Hồ%'

--8.Cho biết tên những giảng viên sinh trước năm 1980 và
--có tham gia đề tài “Phân loại văn bản”
select HoTen
from GiangVien gv, ThamGia tg, DeTai dt
where gv.MaGV = tg.MaGV AND tg.MaDT = dt.MaDT
and Year(NgaySinh)<=1980 and TenDT LIKE N'%Phân loại văn bản%'
select HoTen
from GiangVien gv, ThamGia tg, DeTai dt
where gv.MaGV = tg.MaGV AND tg.MaDT = dt.MaDT
and DATEPART(year, NgaySinh)<=1980 and TenDT LIKE N'%Phân loại văn bản%'

--9.Đưa ra mã giảng viên, tên giảng viên và
--tổng số giờ tham gia nghiên cứu khoa học của từng giảng viên.
select GiangVien.MaGV, HoTen, SUM(SoGio)
from GiangVien, ThamGia
where GiangVien.MaGV = ThamGia.MaGV
group by GiangVien.MaGV, HoTen

select GiangVien.MaGV, HoTen, SUM(SoGio)
from GiangVien left join ThamGia on GiangVien.MaGV = ThamGia.MaGV
group by GiangVien.MaGV, HoTen

--10.Giảng viên Ngô Tuấn Phong sinh ngày 08/09/1986
--địa chỉ Đống Đa, Hà Nội mới tham gia nghiên cứu đề tài khoa học.
--Hãy thêm thông tin giảng viên này vào bảng GiangVien.
insert into GiangVien
values('GV06',N'Ngô Tuấn Phong',N'Đống Đa, Hà Nội','08/09/1986')
select * from GiangVien
--11.Giảng viên Vũ Tuyết Trinh mới chuyển về sống tại quận Tây Hồ, Hà Nội.
--Hãy cập nhật thông tin này.
update GiangVien
set DiaChi = N'Tây Hồ, Hà Nội'
where HoTen = N'Vũ Tuyết Trinh'
--12.Giảng viên có mã GV02 không tham gia bất kỳ đề tài nào nữa.
--Hãy xóa tất cả thông tin liên quan đến giảng viên này trong CSDL.
delete from ThamGia where MaGV = 'GV02'

delete from GiangVien where MaGV = 'GV02'

select * from ThamGia
    --13. Đưa ra ttin gv ko tham gia đề tài nào
select * from GiangVien
where MaGV not in(select MaGV from ThamGia)

select * from GiangVien
where not exists(select * from ThamGia
where GiangVien.MaGV = ThamGia.MaGV)
select * from GiangVien where MaGV IN(
select MaGV from GiangVien
except
select MaGV from ThamGia)
