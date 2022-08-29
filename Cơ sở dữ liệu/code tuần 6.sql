select * from GiangVien;
select * from DeTai;
select * from ThamGia;

--1.Đưa ra thông tin giảng viên có địa chỉ ở quận “Hai Bà Trưng”, sắp xếp theo thứ tự giảm dần của họ tên.
select * from GiangVien where DiaChi like N'%Hai Bà Trưng%' order by HoTen desc;
--2.	Đưa ra danh sách gồm họ tên, địa chỉ, ngày sinh của giảng viên có tham gia vào đề tài “Tính toán lưới”.
select HoTen, DiaChi, NgaySinh from GiangVien gv, DeTai dt, ThamGia tg where gv.MaGV = tg.MaGV and dt.MaDT=tg.MaDT and TenDT = N'Tính toán lưới';
--3.	Đưa ra danh sách gồm họ tên, địa chỉ, ngày sinh của giảng viên có tham gia vào đề tài “Phân loại văn bản” hoặc “Dịch tự động Anh Việt”.
select HoTen, DiaChi, NgaySinh from GiangVien gv, DeTai dt, ThamGia tg where gv.MaGV = tg.MaGV and dt.MaDT=tg.MaDT and (TenDT = N'Phân loại văn bản' or TenDT = N'Dịch tự động Anh Việt');
--4.	Cho biết thông tin giảng viên tham gia ít nhất 2 đề tài.
select * from GiangVien where MaGV in (select MaGV from ThamGia group by MaGV having count(MaDT)>=2);
--5.	Cho biết tên giảng viên tham gia nhiều đề tài nhất.
select * from GiangVien where MaGV in (select MaGV from ThamGia group by MaGV having count(MaDT)>=all(select count(MaDT) from ThamGia group by 
MaGV));
--6.	Đề tài nào tốn ít kinh phí nhất?
select * from DeTai where KinhPhi <= all(select KinhPhi from DeTai);
--7.	Cho biết tên và ngày sinh của giảng viên sống ở quận Tây Hồ và tên các đề tài mà giảng viên này tham gia.
select HoTen, DiaChi, NgaySinh, TenDT from GiangVien gv, DeTai dt, ThamGia tg where gv.MaGV = tg.MaGV and dt.MaDT=tg.MaDT and DiaChi like N'%Tây Hồ%';
--8.	Cho biết tên những giảng viên sinh trước năm 1980 và có tham gia đề tài “Phân loại văn bản”
select HoTen, DiaChi, NgaySinh, TenDT from GiangVien gv, DeTai dt, ThamGia tg where gv.MaGV = tg.MaGV and dt.MaDT=tg.MaDT and 
NgaySinh <= '1980-1-1' and TenDT = N'Phân loại văn bản';
--9.	Đưa ra mã giảng viên, tên giảng viên và tổng số giờ tham gia nghiên cứu khoa học của từng giảng viên.
select gv.MaGV, HoTen, sum(SoGio) as tongsogio from GiangVien gv, DeTai dt, ThamGia tg where gv.MaGV = tg.MaGV and dt.MaDT=tg.MaDT group by gv.MaGV, HoTen;
--cách 2
select GiangVien.MaGV, HoTen, SUM(SoGio)
from GiangVien left join ThamGia on GiangVien.MaGV = ThamGia.MaGV
group by GiangVien.MaGV, HoTen
--10.	Giảng viên Ngô Tuấn Phong sinh ngày 08/09/1986 địa chỉ Đống Đa, Hà Nội mới tham gia nghiên cứu đề tài khoa học. Hãy thêm thông tin giảng viên này vào bảng GiangVien.
insert into GiangVien values ('GV06',N'Ngô Tuấn Phong', N'Đống Đa, Hà Nội', '1986-09-08'); 
delete from GiangVien where MaGV = 'GV06';
--11.	Giảng viên Vũ Tuyết Trinh mới chuyển về sống tại quận Tây Hồ, Hà Nội. Hãy cập nhật thông tin này.
update GiangVien set DiaChi = N'Tây Hồ, Hà Nội' where HoTen = N'Vũ Tuyết Trinh';
--12.	Giảng viên có mã GV02 không tham gia bất kỳ đề tài nào nữa. Hãy xóa tất cả thông tin liên quan đến giảng viên này trong CSDL.
delete from GiangVien where MaGV = 'GV02';