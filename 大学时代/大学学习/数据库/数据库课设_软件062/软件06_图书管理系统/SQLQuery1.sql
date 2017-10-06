CREATE DATABASE DBTest
ON
	(NAME='DBTest', 
	FILENAME='c:\DBTest.mdf',
   	SIZE=15MB,
   	MAXSIZE=100MB,
   	FILEGROWTH=15%)
LOG ON
	(NAME='DBLog',
	FILENAME='c:\DBLog.ldf',
    SIZE=10MB,
	MAXSIZE=20MB,
	FILEGROWTH=2MB);
GO
USE DBTest;
GO
CREATE TABLE ReaderLB(
LBName CHAR(10) PRIMARY KEY,
LBnum SMALLINT NOT NULL CHECK(LBnum>=0),
LBday SMALLINT NOT NULL CHECK(LBday>=0),
LBqx CHAR(4) NOT NULL
);
GO
CREATE TABLE Maneger(
MID CHAR(10) PRIMARY KEY,
MName CHAR(10) NOT NULL,
MSex CHAR(2) CHECK(MSex ='��' or MSex ='Ů'),
Mpwd CHAR(12) NOT NULL,
MAuth CHAR(10) NOT NULL,
MTeleph CHAR(15),
MAddre CHAR(30),
);
GO
CREATE TABLE Room(
RoomNo CHAR(5) PRIMARY KEY,
RoomMID CHAR(10) NOT NULL,
RoomNum SMALLINT CHECK(Roomnum>=0),
RoomAddre CHAR(20),
FOREIGN KEY(RoomMID) REFERENCES Maneger(MID),
);
GO
CREATE TABLE Book(
 BookID CHAR(20) PRIMARY KEY,
 BookNo CHAR(10) NOT NULL,
 BookName CHAR(20)NOT NULL,
 BookWriter CHAR(8)NOT NULL,
 BookPublish CHAR(20)NOT NULL,
 BookPrice FLOAT,
 BookDate DATETIME,
 BookClass CHAR(20),
 BookMain CHAR(200),
 BookPrim CHAR(30),
 BookCopy SMALLINT CHECK(BookCopy>=0),
 BookState CHAR(10)NOT NULL,
 BookRNo CHAR(5)NOT NULL,
FOREIGN KEY(BookRNo) REFERENCES Room(RoomNo),
);
GO
CREATE TABLE Reader(
ReaderID CHAR(10) PRIMARY KEY,
ReaderName CHAR(10) NOT NULL,
ReaderSex CHAR(2) NOT NULL,
ReaderNo CHAR(10) NOT NULL,
ReaderType CHAR(10) NOT NULL,
ReaderDep CHAR(20),
ReaderGrade CHAR(5),
ReaderPref CHAR(20),
ReaderNum SMALLINT CHECK (ReaderNum>=0),
FOREIGN KEY(ReaderType) REFERENCES ReaderLB(LBName),
CHECK(ReaderSex ='��' or ReaderSex ='Ů')
);
GO
CREATE TABLE Borrow(
BookID CHAR(20),
ReaderID CHAR(10),
Outdate DATETIME NOT NULL,
YHdate DATETIME NOT NULL,
Indate DATETIME,
Fine FLOAT,
CLState CHAR(4),
MID CHAR(10) NOT NULL,
PRIMARY KEY(BookID,ReaderID),
FOREIGN KEY(MID) REFERENCES Maneger(MID)
);
GO

CREATE VIEW BookView (ͼ����,�����,����,����,������,�۸�,����ʱ��,ͼ�����,�����,ͼ��״̬,���ڹ���)
AS
SELECT BookID, BookNo, BookName, BookWriter, BookPublish, BookPrice, BookDate, BookClass, BookCopy, BookState,BookRNo
FROM Book
GO
CREATE VIEW ReaderView (���߱��,��������,����,ѧԺ,רҵ,������Ŀ)
AS
SELECT ReaderID,ReaderName,ReaderType,ReaderDep,ReaderPref,ReaderNum
FROM Reader
GO
CREATE VIEW BorrowView (���߱��,����,����,��������,��������)
AS
SELECT ReaderID,BookName,BookWriter,Outdate,YHdate
FROM Borrow,Book
WHERE Borrow.BookID=Book.BookID AND Borrow.Indate=''
GO
CREATE VIEW HistoryView (���߱��,����,��������,�黹����)
AS
SELECT ReaderID,BookName,Outdate,Indate
FROM Borrow,Book
WHERE Borrow.BookID=Book.BookID AND Borrow.Indate !=''
GO
CREATE VIEW FineView (���߱��,ͼ����,����,��������,�黹����,����,����״̬,����Ա��)
AS
SELECT ReaderID,Book.BookID,BookName,Outdate,Indate,Fine,CLState,MID
FROM Borrow,Book
WHERE Borrow.BookID=Book.BookID AND Fine !=0
GO

CREATE TRIGGER Trigger_Reader_delete
ON Reader
FOR DELETE
AS BEGIN
	DECLARE @ReaderID CHAR(10)
	SELECT @ReaderID=ReaderID
	FROM deleted
	DELETE FROM Borrow
	WHERE ReaderID=@ReaderID
END;
GO
CREATE TRIGGER Trigger_Borrow_Book
ON Borrow
FOR INSERT
AS BEGIN
	DECLARE @BookID CHAR(20)
	SELECT @BookID=BookID
	FROM inserted
	IF ((SELECT BookState FROM Book WHERE BookID=@BookID)='�ɽ�')
		BEGIN
			UPDATE Book
			SET BookCopy=BookCopy-1
			WHERE BookID=@BookID
			IF ((SELECT BookCopy FROM Book WHERE BookID=@BookID)=0)
				BEGIN
					UPDATE Book
					SET BookState='���ɽ�'
					WHERE BookID=@BookID
				END
		END
	ELSE
		BEGIN
			ROLLBACK
			PRINT('��������,�޷�����')
		END
END;
GO
CREATE TRIGGER Trigger_Return_Book
ON Borrow
FOR UPDATE
AS BEGIN
	DECLARE @BookID CHAR(20)
	SELECT @BookID=BookID
	FROM inserted
	BEGIN
		UPDATE Book
		SET BookCopy=BookCopy+1,BookState='�ɽ�'
		WHERE BookID=@BookID
	END
END;
GO
CREATE TRIGGER Trigger_Borrow_Reader
ON Borrow
FOR INSERT
AS BEGIN
	DECLARE @ReaderID CHAR(10)
	DECLARE @ReaderType CHAR(10)
	SELECT @ReaderID=inserted.ReaderID,@ReaderType=ReaderType
	FROM inserted,Reader
	WHERE Reader.ReaderID=inserted.ReaderID
	IF((SELECT ReaderNum FROM Reader WHERE ReaderID=@ReaderID) <(SELECT LBnum FROM ReaderLB WHERE LBName=@ReaderType))
		BEGIN
			UPDATE Reader
			SET ReaderNum=ReaderNum+1
			WHERE ReaderID=@ReaderID
		END
	ELSE
		BEGIN
			ROLLBACK
			PRINT('�Ѵ�����������')
		END
END;
GO
CREATE TRIGGER Trigger_Return_Reader
ON Borrow
FOR UPDATE
AS BEGIN
	DECLARE @ReaderID CHAR(10)
	SELECT @ReaderID=ReaderID
	FROM inserted
	BEGIN
		UPDATE Reader
		SET ReaderNum=ReaderNum-1
		WHERE ReaderID=@ReaderID
	END
END;
GO
CREATE TRIGGER Trigger_Book_Insert
ON Book
FOR INSERT
AS BEGIN
	DECLARE @BookRNo CHAR(5)
	SELECT @BookRNo=BookRNo
	FROM inserted
	UPDATE Room
	SET RoomNum=RoomNum+1
	WHERE RoomNo=@BookRNo
END;
GO
CREATE TRIGGER Trigger_Book_delete
ON Book
FOR DELETE
AS BEGIN
	DECLARE @BookRNo CHAR(5)
	SELECT @BookRNo=BookRNo
	FROM deleted
	UPDATE Room
	SET RoomNum=RoomNum-1
	WHERE RoomNo=@BookRNo
END;
GO

CREATE PROCEDURE Book_Insert
	@BookID CHAR(20),
	@BookNo CHAR(10),
	@BookName CHAR(20),
	@BookWriter CHAR(8),
	@BookPublish CHAR(20),
	@BookPrice FLOAT,
	@BookDate DATETIME,
	@BookClass CHAR(20),
	@BookMain CHAR(200),
	@BookPrim CHAR(30),
	@BookCopy SMALLINT,
	@BookState CHAR(10),
	@BookRNo CHAR(5)
AS	
INSERT INTO Book
VALUES(@BookID ,@BookNo,@BookName,@BookWriter ,@BookPublish ,@BookPrice,@BookDate,@BookClass ,@BookMain ,@BookPrim ,@BookCopy ,@BookState ,@BookRNo);
GO
CREATE PROCEDURE Reader_Insert
	@ReaderID CHAR(10),
	@ReaderName CHAR(10),
	@ReaderSex CHAR(2),
	@ReaderNo CHAR(10),
	@ReaderType CHAR(20),
	@ReaderDep CHAR(20),
	@ReaderGrade CHAR(5),
	@ReaderPref CHAR(20),
	@ReaderNum SMALLINT
AS	
INSERT INTO Reader
VALUES(@ReaderID,@ReaderName,@ReaderSex,@ReaderNo ,@ReaderType,@ReaderDep , @ReaderGrade ,@ReaderPref ,@ReaderNum);
GO
CREATE PROCEDURE Maneger_Insert
	@MID CHAR(10),
	@MName CHAR(10),
	@MSex CHAR(2),
	@Mpwd CHAR(8),
	@MAuth CHAR(8),
	@MTeleph CHAR(15),
	@MAddre CHAR(30)
AS	
INSERT INTO Maneger
VALUES(@MID , @MName ,@MSex  ,@Mpwd  ,@MAuth ,@MTeleph ,@MAddre);
GO
CREATE PROCEDURE Borrow_Insert
	@BookID CHAR(20),
	@ReaderID CHAR(10),
	@MID CHAR(10)
AS	
	DECLARE @Outdate DATETIME
	SELECT @Outdate=GETDATE()
	DECLARE @ReaderType CHAR(10)
	SELECT @ReaderType=ReaderType FROM Reader WHERE ReaderID=@ReaderID
	DECLARE @LBday SMALLINT
	SELECT @LBday=LBday FROM ReaderLB WHERE LBName=@ReaderType
	DECLARE @YHdate DATETIME
	SELECT @YHdate=DATEADD(day,@LBday,@Outdate)

INSERT INTO Borrow
VALUES(@BookID,@ReaderID,@Outdate,@YHdate,'','','',@MID );
GO
CREATE PROCEDURE Query_Reader
AS	
SELECT *		
FROM ReaderView
GO
CREATE PROCEDURE Query_Book_Writer
	@BookWriter char(8)
AS	
SELECT *
FROM BookView
WHERE ���� LIKE '%'+ltrim(@BookWriter)+'%';
GO
CREATE PROCEDURE Query_Book_No
	@BookNo char(10)
AS
SELECT *
FROM BookView
WHERE  �����=ltrim(@BookNo);
GO
CREATE PROCEDURE Delete_Reader
	@ReaderNo char(10)
AS
DELETE
FROM Reader
WHERE ReaderNo = ltrim(@ReaderNo);
GO
CREATE PROCEDURE Delete_Book
	@BookID char(20)
AS
DELETE
FROM Book
WHERE BookID= ltrim(@BookID);
GO
CREATE PROCEDURE Borrow_Update
	@BookID CHAR(20),
	@ReaderID CHAR(10),
	@CLState CHAR(4),
	@MID CHAR(10)
AS	
	DECLARE @Indate DATETIME
	SELECT @Indate=GETDATE()
	DECLARE @Fine FLOAT
	SELECT @Fine=CONVERT(FLOAT,DateDiff("d",YHdate,@Indate))
	FROM Borrow WHERE ReaderID=@ReaderID AND BookID=@BookID
UPDATE Borrow
SET Indate=@Indate,Fine=@Fine,CLState=@CLState,MID=@MID
WHERE ReaderID=@ReaderID AND BookID=@BookID;

ReaderLB 
Insert into ReaderLB values ('��ʦ','10','60', 'ʮ��')
Insert into ReaderLB values ('ѧ��','8','30', '����')
Insert into ReaderLB values ('���','6','30', '����')
	
Maneger
Insert into Maneger values ('01', 'admin','��','admin', 'ϵͳ����Ա', '13810123456', '����')
Insert into Maneger values ('02', '����','��','000000', 'ͼ�����Ա', '13810456789', '����')
Insert into Maneger values ('03', '����','��','123456', 'ͼ�����Ա', '13810456789', '����')

Room
Insert into Room values ('101', '02','0','����У��ͼ�����')
Insert into Room values ('102', '03','0','����У��ͼ�����')

Book
Insert into Book values ('9787040195835', '101001','���ݿ�ϵͳ����','��ɺ', '�ߵȽ���������', '33.8', '2006-5-17','�����', 'ϵͳȫ��Ĳ������ݿ�ϵͳ�Ļ������ۡ��������ɺͻ�������', '���ݿ�','3', '�ɽ�', '101')
Insert into Book values ('9787040191234', '101002','���������ư����̳�','���֪', '�廪��ѧ������', '25', '2008-6-17','�����', '�������������Ƽ���', 'ASP','4', '�ɽ�', '101')
Insert into Book values ('9787040192344', '101003','��·����Ӽ�������','�����', '��е��ҵ������', '38.2', '2008-3-11','���ӵ�·', '��·����ģ����Ӽ��������ֵ��Ӽ���', '��·','5', '�ɽ�', '101')
Insert into Book values ('9787040196543', '102001','����˻��������','������', '�ߵȽ���������', '18.6', '2004-2-5','�˻�����', 'ȫ��Ľ�������Ľ������', '����','4', '�ɽ�', '102')
Insert into Book values ('9787040196789', '102002','�����������','������', '�ߵȽ���������', '48.5', '2007-8-5','�������', '������������Ĳ����뷢չ', '���','5', '�ɽ�', '102')
Insert into Book values ('9787040199701', '102003','��Ϣ����','����֥', '�廪��ѧ������', '32', '2003-7-15','��Ϣ', '��Ϣ�ļ�����������չ', '��Ϣ','5', '�ɽ�', '102')

Reader
Insert into Reader values ('001', '����','��','0614060104', 'ѧ��', '���������Ϣ����', '06','�������',0)
Insert into Reader values ('002', '����','��','0414060106', 'ѧ��', '���������Ϣ����', '04','�������',0)
Insert into Reader values ('003', '����','��','0614060101', 'ѧ��', '���������Ϣ����','06', '�������',0)
Insert into Reader values ('004', 'Τ��','��','0613060107', 'ѧ��', '���������Ϣ����', '06','�Զ���',0)
Insert into Reader values ('005', '��˶','��','0612060111', 'ѧ��', '����', '07','���',0)
Insert into Reader values ('006', '����','��','0707030106', 'ѧ��', '��ý������', '08','��������',0)

Borrow
Insert into Borrow values ('9787040191234', '003','2009-3-3','2009-4-3', '', '', '��','03')
Insert into Borrow values ('9787040196543', '004','2009-4-3','2009-5-3', '', '', '��','02')
Insert into Borrow values ('9787040196543', '002','2009-6-3','2009-7-3', '', '', '��','03')

select * from readerlb
select * from reader
select * from maneger
select * from room
select * from borrow
select * from book

select * from bookview where bookid='9787040196543'
select * from borrowview 
select * from historyview 
select * from Fineview

select * from reader where readerid='002'
select * from book


exec Query_Book_No '101002'
exec Query_Book_Writer '��ɺ' 

exec Borrow_Insert '9787040192344','003','02'

exec Borrow_Update '9787040191234','003','��','02'