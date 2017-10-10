--���28��


--����鲿�ŵ���ϸ��
select * from codedata 
where codetype = '������鲿������';

--��ϸ����sql3096
SELECT gl.shenqingh,
       gl.shenqingrlx,
       gl.shengfendm,
       gl.youxianscqqlx,
       gl.youxianscfs,
       gl.banlifs,
       gl.querensj,
       gl.zhuanlilx,
       gl.gl_yxsc_ajscb_id,
       zhu.zhuanlimc,
       gl.youxianscbh,
       gl.youxiansccjrq,
       gbb.bumc,
       gbb.chumc,
       gx.shishenscy,
       gx.shenqingr,
       gx.chushenhgr,
       gx.shishenscjar,
       gl.guobie,
       gx.jkajscyjsr,
       gl.zhufenlh,
       gx.huianrq,
       zllx.codename       as zhuanlilx_mc,
       sqrlx.codename      as shenqingrlx_mc,
       gs.qingqiulxmc      as youxianscqqlx_mc,
       scfs.shechafsmc     as youxianscfs_mc,
       --gx.bumendm,  
       --gx.chushidm,  
       decode(gl.zhuanlilx,
              '1',
              s.renyuanxm,
              '2',
              x.renyuanxm,
              '3',
              w.shenchayxm) as renyuanxm, --����ϸ����ڡ�
       gx.gongburq, --��������
       gx.jinrussrq, -- ����ʵ������
       sab.sstar, --ʵ���᰸��
       gx.yitongfwr, --һͨ��������
       gl.anjianzt,
       ajzt.codename as anjianzt_mc, --�״ν᰸��
       gx.chuanlx, --�״ν᰸����
       calx.codename as calxmc, --��������
       gl.chuzhengbm,
       czbm.chuzhengbmmc as chuzhengbm_mc,
       gb.codename as guobie_mc,
       qh.gjxzqhmc as shengfendm_mc, --�ӿ참�����Ա������
       gl.feiyongbh,
       decode(gl.feiyongclbj, '1', '��', '��') as feiyongclbj,
       blfs.codename as banlifs_mc
  FROM gl_yxsc_ajscb gl
 inner join gg_zlx_zhu zhu
    on zhu.shenqingh = gl.shenqingh
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = gl.shenqingh
  left join gl_cspz_jgdzb gbb
    on gbb.jigouid_pk = gx.jigoufk
  left join gl_yxsc_czbmpzb czbm
    on czbm.chuzhengbmdm = gl.chuzhengbm
  left join gl_yxsc_scfspzb scfs
    on scfs.shenchafsdm = gl.youxianscfs
  left join gl_yxsc_sclxpzb gs
    on gs.qingqiulxdm = gl.youxianscqqlx
  left join codedata zllx
    on zllx.codetype = '�������ר������'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '�������루���Һ͵������룩'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[����]����״̬����'
   AND ajzt.CODEVALUE = gl.anjianzt
  left join codedata calx
    on calx.codetype = '[����ʵ��]��������'
   AND calx.CODEVALUE = gx.chuanlx
  left join zpt_sjwh_gjxzqh qh
    on qh.gjxzqhdm = gl.shengfendm
  left join (SELECT ss.SHENQINGHAO as SHENQINGHAO,
                    --ss.jinrussrq   as sstar,
                    yh.renyuanxm as renyuanxm
               FROM ss_scgz_ajscb ss, zpt_yhqxgl_yh yh
              WHERE ss.SHUOSHUSCY = yh.yonghuzh
                and ss.lishibj = '1') s
    on s.SHENQINGHAO = zhu.shenqingh
   and zhu.zhuanlilx = '1'
  left join (select min(scb.jinrussrq) as sstar, scb.shenqinghao
               from ss_scgz_ajscb scb
              group by shenqinghao) sab
    on sab.shenqinghao = zhu.shenqingh
   and zhu.zhuanlilx = '1'
  left join (SELECT xx.shenqingh as SHENQINGHAO, yh.renyuanxm as renyuanxm
               FROM XX_AJSCB xx, zpt_yhqxgl_yh yh
              where xx.shenchaydm = yh.yonghuzh) x
    on x.SHENQINGHAO = zhu.shenqingh
   and zhu.zhuanlilx = '2'
  left join wg_ajscb w
    on w.shenqingh = zhu.shenqingh
   and zhu.zhuanlilx = '3'
 WHERE gl.shanchubj = '0' 
   and gl.youxianscqqrq >= '20120801'
   and gl.youxianscqqrq <= '20130831'
   and gl.shenqingh in
   (SELECT a.SHENQINGH FROM GL_YXSC_SCJAB A
    UNION ALL
    SELECT c.SHENQINGH FROM GL_YXSC_AJSCTJB C)


--��ϸ���sql3096
SELECT gl.gl_yxsc_ajscb_id,
       gl.shenqingh, --ȡ�̻�
       gl.zhuanlilx, --ȡ�̻�
       zhu.zhuanlimc,
       gl.shenqingrlx, --ȡ�̻�
       gl.youxianscbh,
       gl.youxianscqqlx, --ȡ�̻�
       gl.youxianscfs, --ȡ�̻�
       gl.youxiansccjrq,
       gbb.bumc,
       gbb.chumc,
       gx.shishenscy,
       gx.shenqingr,
       gx.chushenhgr,
       gx.shishenscjar,
       gl.guobie,
       gl.shengfendm, --ȡ�̻�
       gx.jkajscyjsr,
       gl.zhufenlh,
       gl.banlifs, --ȡ�̻�
       gx.huianrq,
       gl.querensj, --ȡ�̻�
       zllx.codename       as zhuanlilx_mc,
       sqrlx.codename      as shenqingrlx_mc,
       gs.qingqiulxmc      as youxianscqqlx_mc,
       scfs.shechafsmc     as youxianscfs_mc,
       --gx.bumendm,  
       --gx.chushidm,  
       decode(gl.zhuanlilx,
              '1',
              s.renyuanxm,
              '2',
              x.renyuanxm,
              '3',
              w.shenchayxm) as renyuanxm, --����ϸ����ڡ�
       gx.gongburq, --��������
       gx.jinrussrq, -- ����ʵ������
       sab.sstar, --ʵ���᰸��
       gx.yitongfwr, --һͨ��������
       gl.anjianzt,
       ajzt.codename as anjianzt_mc, --�״ν᰸��
       gx.chuanlx, --�״ν᰸����
       calx.codename as calxmc, --��������
       gl.chuzhengbm,
       czbm.chuzhengbmmc as chuzhengbm_mc,
       gb.codename as guobie_mc,
       qh.gjxzqhmc as shengfendm_mc, --�ӿ참�����Ա������
       gl.feiyongbh,
       decode(gl.feiyongclbj, '1', '��', '��') as feiyongclbj,
       blfs.codename as banlifs_mc
  FROM gl_yxsc_ajscb gl
 inner join gg_zlx_zhu zhu
    on zhu.shenqingh = gl.shenqingh
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = gl.shenqingh
  left join gl_cspz_jgdzb gbb
    on gbb.jigouid_pk = gx.jigoufk
  left join gl_yxsc_czbmpzb czbm
    on czbm.chuzhengbmdm = gl.chuzhengbm
  left join gl_yxsc_scfspzb scfs
    on scfs.shenchafsdm = gl.youxianscfs
  left join gl_yxsc_sclxpzb gs
    on gs.qingqiulxdm = gl.youxianscqqlx
  left join codedata zllx
    on zllx.codetype = '�������ר������'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '�������루���Һ͵������룩'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[����]����״̬����'
   AND ajzt.CODEVALUE = gl.anjianzt
  left join codedata calx
    on calx.codetype = '[����ʵ��]��������'
   AND calx.CODEVALUE = gx.chuanlx
  left join zpt_sjwh_gjxzqh qh
    on qh.gjxzqhdm = gl.shengfendm

  left join (SELECT ss.SHENQINGHAO as SHENQINGHAO,
                    --ss.jinrussrq   as sstar,
                    yh.renyuanxm as renyuanxm
               FROM ss_scgz_ajscb ss, zpt_yhqxgl_yh yh
              WHERE ss.SHUOSHUSCY = yh.yonghuzh
                and ss.lishibj = '1') s
    on s.SHENQINGHAO = zhu.shenqingh
   and zhu.zhuanlilx = '1'
  left join (select min(scb.jinrussrq) as sstar, scb.shenqinghao
               from ss_scgz_ajscb scb
              group by shenqinghao) sab
    on sab.shenqinghao = zhu.shenqingh
   and zhu.zhuanlilx = '1'

  left join (SELECT xx.shenqingh as SHENQINGHAO, yh.renyuanxm as renyuanxm
               FROM XX_AJSCB xx, zpt_yhqxgl_yh yh
              where xx.shenchaydm = yh.yonghuzh) x
    on x.SHENQINGHAO = zhu.shenqingh
   and zhu.zhuanlilx = '2'

  left join wg_ajscb w
    on w.shenqingh = zhu.shenqingh
   and zhu.zhuanlilx = '3'
 WHERE gl.shanchubj = '0'
--   and gl.shenqingh = '2011103004640';
and gl.youxianscqqrq >= '20120801' and gl.youxianscqqrq <= '20130831'


--ͬ���
create or replace public synonym GL_YXSC_AJSCTJB
for GL_YXSC_AJSCTJB 

--�������ݴ�ͳ�ƿ⵽���Կ�
insert into GL_YXSC_AJSCTJB
select * from GL_YXSC_AJSCTJB@LINK_GLCX_SCZQ_USER;

insert into GL_YXSC_SCJAB
select * from GL_YXSC_SCJAB@LINK_GLCX_SCZQ_USER;

-- ��ϸ��ѯ��sql3068
SELECT ac.shenqingh,
       ac.shenqingrlx,
       ac.shengfendm,
       ac.youxianscqqlx,
       ac.youxianscfs,
       -- ac.youxiansccjrq, 
       ac.banlifs,
       ac.querensj,
       ac.zhuanlilx,
       gl.gl_yxsc_ajscb_id,
       gl.zhufenlh,
       gl.guobie,
       gl.youxianscbh,
       gl.feiyongbh,
       gl.anjianzt as cjanjianzt,
       decode(gl.feiyongclbj, '1', '��', '��') as feiyongclbj,
       gs.qingqiulxmc as youxianscqqlx_mc,
       qh.gjxzqhmc as shengfendm_mc,
       scfs.shechafsmc as youxianscfs_mc,
       czbm.chuzhengbmmc as chuzhengbm_mc,
       zllx.codename as zhuanlilx_mc,
       sqrlx.codename as shenqingrlx_mc,
       gb.codename as guobie_mc,
       blfs.codename as banlifs_mc,
       gl.chuzhengbm
  FROM (SELECT a.SHENQINGH,
               a.shenqingrlx,
               a.shengfendm,
               a.youxianscqqlx,
               a.youxianscfs,
               a.youxianscqqrq,
               a.banlifs,
               a.querensj,
               a.zhuanlilx
          FROM GL_YXSC_SCJAB A
        UNION ALL
        SELECT c.SHENQINGH,
               c.shenqingrlx,
               c.shengfendm,
               c.youxianscqqlx,
               c.youxianscfs,
               c.youxianscqqrq,
               c.banlifs,
               c.querensj,
               c.zhuanlilx
          FROM GL_YXSC_AJSCTJB C) ac
 inner join gl_yxsc_ajscb gl
    on gl.shenqingh = ac.shenqingh
  left join gl_yxsc_czbmpzb czbm
    on czbm.chuzhengbmdm = gl.chuzhengbm
  left join gl_yxsc_scfspzb scfs
    on scfs.shenchafsdm = gl.youxianscfs
  left join gl_yxsc_sclxpzb gs
    on gs.qingqiulxdm = gl.youxianscqqlx
  left join zpt_sjwh_gjxzqh qh
    on qh.gjxzqhdm = gl.shengfendm
--���뼯
  left join codedata zllx
    on zllx.codetype = '�������ר������'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '�������루���Һ͵������룩'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[����]����״̬����'
   AND ajzt.CODEVALUE = gl.anjianzt
 WHERE gl.shanchubj = '0'
   and gl.youxianscqqrq >= '20120801'
   and gl.youxianscqqrq <= '20130831'

-- �����һ��
select s.shanchubj,s.youxiansczt,s.* from gl_yxsc_ajscb s where shenqingh = '2013100013416'

select * from GL_YXSC_AJSCTJB where shenqingh = '2013100013416';
select * from GL_YXSC_SCJAB where shenqingh = '2013100013416';


--��ϸ��ѯ��sql3802
SELECT gl.gl_yxsc_ajscb_id,
       gl.shenqingh,
       gl.zhuanlilx,
       gl.shenqingrlx,
       gl.youxianscbh,
       gl.youxianscqqlx,
       gl.youxianscfs,
       gl.youxiansccjrq,
       gl.guobie,
       gl.shengfendm,
       gl.zhufenlh,
       gl.banlifs,
       gl.querensj,
       zllx.codename as zhuanlilx_mc,
       sqrlx.codename as shenqingrlx_mc,
       gs.qingqiulxmc as youxianscqqlx_mc,
       scfs.shechafsmc as youxianscfs_mc,
       czbm.chuzhengbmmc as chuzhengbm_mc,
       gb.codename as guobie_mc,
       qh.gjxzqhmc as shengfendm_mc,
       gl.feiyongbh,
       gl.anjianzt as cjanjianzt,
       decode(gl.feiyongclbj, '1', '��', '��') as feiyongclbj,
       blfs.codename as banlifs_mc,
       gl.chuzhengbm
  FROM gl_yxsc_ajscb gl
  left join gl_yxsc_czbmpzb czbm
    on czbm.chuzhengbmdm = gl.chuzhengbm
  left join gl_yxsc_scfspzb scfs
    on scfs.shenchafsdm = gl.youxianscfs
  left join gl_yxsc_sclxpzb gs
    on gs.qingqiulxdm = gl.youxianscqqlx
  left join codedata zllx
    on zllx.codetype = '�������ר������'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '�������루���Һ͵������룩'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[����]����״̬����'
   AND ajzt.CODEVALUE = gl.anjianzt
  left join zpt_sjwh_gjxzqh qh
    on qh.gjxzqhdm = gl.shengfendm
 WHERE gl.shanchubj = '0'
   and gl.querensj >= '20120801'
   and gl.querensj <= '20130831'
--����sql�ȶ�
  and not exists
(select 1 from 
        (SELECT * FROM 
                (SELECT A.*
                  FROM GL_YXSC_SCJAB A
                  UNION ALL
                  SELECT B.*, '', '', '', ''
                  FROM GL_YXSC_AJSCTJB B
                  WHERE TONGJIND || TONGJIYF = TO_CHAR(SYSDATE, 'YYYYMM')
                )
         where querensj between 20130801 and 20140831 
        ) xqp 
where xqp.shenqingh = gl.shenqingh
);

-- ��ϸ��ѯ��sql
select ac.SHENQINGH,ac.shenqingrlx,ac.shengfendm,ac.youxianscqqlx,ac.youxianscfs,ac.youxianscqqrq,ac.banlifs,ac.querensj,ac.zhuanlilx
from 
(SELECT a.SHENQINGH,a.shenqingrlx,a.shengfendm,a.youxianscqqlx,a.youxianscfs,a.youxianscqqrq,a.banlifs,a.querensj,a.zhuanlilx
FROM GL_YXSC_SCJAB A
UNION ALL
SELECT c.SHENQINGH,c.shenqingrlx,c.shengfendm,c.youxianscqqlx,c.youxianscfs,c.youxianscqqrq,c.banlifs,c.querensj,c.zhuanlilx
FROM GL_YXSC_AJSCTJB C
) ac
where ac.querensj between 20130801 and 20130831


-- ��Ǯ��sql
SELECT B.*
  FROM (SELECT A.*
          FROM GL_YXSC_SCJAB A
        UNION ALL
        SELECT C.*, '', '', '', ''
          FROM GL_YXSC_AJSCTJB C
         -- ͳ���·������ڵ���
         -- WHERE TONGJIND || TONGJIYF = TO_CHAR(SYSDATE, 'YYYYMM')
       ) B
where B.querensj between 20130801 and 20130831
order by bumendm nulls first

select * from gl_yxsc_ajscb where shenqingh = '2010800690083'
select shenqingh ,count(*) from gl_yxsc_ajscb ac group by ac.shenqingh having count(*)>1
delete from GL_YXSC_AJSCTJB

select * from zpt_qxjs_qxdy

-- ��������״ν᰸����
select b.shenqingh,
       b.shenqingrlx,
       b.shengfendm,
       b.youxianscqqlx,
       b.shanchubj,
       b.banlifs,
       b.chuzhengbm,
       b.zhuanlilx,
       b.youxianscqqrq,
       b.youxianscbh,
       b.youxianscfs,
       b.querensj,
       b.youxiansczt,
       
       gx.bumendm,
       gx.shishenscy,
       gs.qingqiulxmc,
       gj.bumc,
       sc.zhijiancar,
       sc.shuoshuscy,
       sc.shuoshujgid_fk,
       zpt.renyuanxm
  from -- ��ʵ����ѯ�״ν᰸��(��С�ʼ������)
       (select ssxh.zhijiancar,
               ssxh.shuoshuscy,
               ssxh.shuoshujgid_fk,
               ssxh.shenqinghao
        --��������
          from (SELECT ROW_NUMBER() OVER(PARTITION BY ss.shenqinghao ORDER BY ss.zhijiancar asc) AS xh,
                       ss.*
                  from ss_scgz_ajscb ss
                 where anjianssjd = '9'
                   and chuanlx in ('05', '06', '07', '08', '20', '21', '22')
                   and zhijianbz in ('2', '4')) ssxh
         where xh = 1) sc
 inner join gl_yxsc_ajscb b
    on b.shenqingh = sc.shenqinghao
 inner join gl_yxsc_sclxpzb gs
    on b.youxianscqqlx = gs.qingqiulxdm
 inner join gg_zlx_zhu zhu
    on zhu.shenqingh = b.shenqingh
 inner join ss_scgz_ajscb ss
    on ss.shenqinghao = b.shenqingh
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = b.shenqingh
  left join gl_cspz_jgdzb gj
    on gj.jigouid_pk = gx.jigoufk
  left join zpt_yhqxgl_yh zpt
    on zpt.yonghuzh = ss.shuoshuscy
 where b.youxiansczt = '2'

-- δ�᰸����
select b.shenqingh,
       b.shenqingrlx,
       b.shengfendm,
       b.youxianscqqlx,
       b.shanchubj,
       b.banlifs,
       b.chuzhengbm,
       b.zhuanlilx,
       b.youxianscqqrq,
       b.youxianscbh,
       b.youxianscfs,
       b.querensj,
       b.youxiansczt,
       gx.bumendm,
       gx.shishenscy,
       gs.qingqiulxmc,
       gj.bumc
  from gl_yxsc_ajscb b
 inner join gl_yxsc_sclxpzb gs
    on b.youxianscqqlx = gs.qingqiulxdm
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = b.shenqingh
  left join gl_cspz_jgdzb gj
    on gj.jigouid_pk = gx.jigoufk
 where b.shenqingh not in
       ( -- ��������״ν᰸�����
        select b.shenqingh
          from -- ��ʵ������״ν᰸��(�ʼ������)�������
                (select shenqinghao
                 --��������
                   from (SELECT ROW_NUMBER() OVER(PARTITION BY ss.shenqinghao ORDER BY ss.zhijiancar asc) AS xh,
                                ss.*
                           from ss_scgz_ajscb ss
                          where anjianssjd = '9'
                            and chuanlx in
                                ('05', '06', '07', '08', '20', '21', '22')
                            and zhijianbz in ('2', '4'))
                  where xh = 1) sc
         inner join gl_yxsc_ajscb b
            on b.shenqingh = sc.shenqinghao
         where b.youxiansczt = '2')

-- �����״ν᰸��
create table GL_YXSC_SCJAB as
select '2013' as tongjind,
       '12' as tongjiyf,
       b.shenqingh,
       b.shenqingrlx,
        b.shengfendm,
        b.youxianscqqlx,
        b.shanchubj,
        b.banlifs,
        b.chuzhengbm,
        b.zhuanlilx,
        b.youxianscqqrq,
        b.youxianscbh,
        b.youxianscfs,
        b.querensj,
        b.youxiansczt,
        gx.bumendm,
        gx.shishenscy,
        gs.qingqiulxmc,
        gj.bumc,
        ss.zhijiancar,
        ss.shuoshuscy,
        ss.shuoshujgid_fk,
        zpt.renyuanxm
   from gl_yxsc_ajscb b
  inner join gl_yxsc_sclxpzb gs on b.youxianscqqlx = gs.qingqiulxdm 
  inner join gg_zlx_zhu zhu on zhu.shenqingh = b.shenqingh 
  inner join ss_scgz_ajscb ss on ss.shenqinghao = b.shenqingh
   left join gl_yxsc_jkajxx gx on gx.shenqingh = b.shenqingh   
   left join gl_cspz_jgdzb gj on gj.jigouid_pk = gx.jigoufk 
   left join zpt_yhqxgl_yh zpt on zpt.yonghuzh = ss.shuoshuscy
where 1 = 2;
-- Add comments to the table
comment on table GL_YXSC_SCJAB is 
'��������״ν᰸��';
-- Add comments to the columns
comment on column GL_YXSC_SCJAB.tongjind is
'ͳ�����';
comment on column GL_YXSC_SCJAB.tongjiyf is
'ͳ���·�';
comment on column GL_YXSC_SCJAB.zhijiancar is
'�״ν᰸�գ���С�ʼ�����գ�';
comment on column GL_YXSC_SCJAB.shuoshuscy is
'�������Ա���û��ʺţ�';
comment on column GL_YXSC_SCJAB.renyuanxm is
'�������Ա���ƣ���Ա������';
comment on column GL_YXSC_SCJAB.shuoshujgid_fk is
'��������id';
drop table GL_YXSC_AJSCTJB

-- �����������ͳ�Ʊ�
create table GL_YXSC_AJSCTJB as
select '2013' as tongjind,
       '12' as tongjiyf,
       b.shenqingh,
       b.shenqingrlx,
       b.shengfendm,
       b.youxianscqqlx,
       b.shanchubj,
       b.banlifs,
       b.chuzhengbm,
       b.zhuanlilx,
       b.youxianscqqrq,
       b.youxianscbh,
       b.youxianscfs,
       b.querensj,
       b.youxiansczt,
       gx.bumendm,
       gx.shishenscy,
       gs.qingqiulxmc,
       gj.bumc
  from gl_yxsc_ajscb b
 inner join gl_yxsc_sclxpzb gs
    on b.youxianscqqlx = gs.qingqiulxdm
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = b.shenqingh
  left join gl_cspz_jgdzb gj
    on gj.jigouid_pk = gx.jigoufk
-- ��ѯ���Ϊ��
  and 1 = 2;
-- Add comments to the table 
comment on table GL_YXSC_AJSCTJB is 
'�������ͳ�Ʊ�';
-- Add comments to the columns 
comment on column GL_YXSC_AJSCTJB.tongjiyf is
'ͳ���·�';
comment on column GL_YXSC_AJSCTJB.tongjind is
'ͳ�����';

-- ��Ǯ��sql
select 
--b.querensj,
       b.shenqingh,
       b.shenqingrlx,
       b.shengfendm,
       b.youxianscqqlx,
       gs.qingqiulxmc,
       b.banlifs,
       b.chuzhengbm,
       b.zhuanlilx,
       gx.bumendm,
       gj.bumc
  from gl_yxsc_ajscb b
 inner join gl_yxsc_sclxpzb gs
    on gs.qingqiulxdm = b.youxianscqqlx
 inner join gg_zlx_zhu zhu
    on zhu.shenqingh = b.shenqingh
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = b.shenqingh
  left join gl_cspz_jgdzb gj
    on gj.jigouid_pk = gx.jigoufk
 where b.shanchubj = '0'
--
and b.querensj >= '20130801'
and b.querensj <= '20130831'

-- ͳ�ƿ⣺��ѯ��ǰ�ı�
-- 107513 admin ͳ����ϵͳ ͳ������
select * from i_query t where t.uuid='0C1V0MVI6TDD42C5';
��������ͳ�Ʊ�

-- ��ѯ����Ŵ���
select b.shenqingh,
       b.shenqingrlx,
       b.shengfendm,
       b.youxianscqqlx,
       gs.qingqiulxmc,
       b.banlifs,
       b.chuzhengbm,
       b.zhuanlilx,
       gx.bumendm,
       gj.bumc
  from gl_yxsc_sclxpzb gs, gl_yxsc_ajscb b
 inner join gg_zlx_zhu zhu
    on zhu.shenqingh = b.shenqingh
  left join gl_yxsc_jkajxx gx
    on gx.shenqingh = b.shenqingh
  left join gl_cspz_jgdzb gj
    on gj.jigouid_pk = gx.jigoufk
 where gs.qingqiulxdm = b.youxianscqqlx
   and b.shanchubj = '0'
   AND (b.querensj >= '20130101')
   AND (b.querensj <= '20131231')
   and b.shenqingh = '2013101999437'
 order by gx.bumendm nulls first;

select shanchubj,querensj,gl_yxsc_ajscb.*
from gl_yxsc_ajscb
where shenqingh = '2013101999437' 
or shenqingh = '201210359886X'
