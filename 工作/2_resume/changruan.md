--多的28件


--局审查部门的明细表
select * from codedata 
where codetype = '优先审查部门名称';

--明细表新sql3096
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
              w.shenchayxm) as renyuanxm, --初审合格日期、
       gx.gongburq, --公布日期
       gx.jinrussrq, -- 进入实审日期
       sab.sstar, --实申提案日
       gx.yitongfwr, --一通发文日期
       gl.anjianzt,
       ajzt.codename as anjianzt_mc, --首次结案日
       gx.chuanlx, --首次结案类型
       calx.codename as calxmc, --出案名称
       gl.chuzhengbm,
       czbm.chuzhengbmmc as chuzhengbm_mc,
       gb.codename as guobie_mc,
       qh.gjxzqhmc as shengfendm_mc, --加快案件审查员接收日
       gl.feiyongbh,
       decode(gl.feiyongclbj, '1', '是', '否') as feiyongclbj,
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
    on zllx.codetype = '优先审查专利类型'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '基本代码（国家和地区代码）'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[公共]案件状态代码'
   AND ajzt.CODEVALUE = gl.anjianzt
  left join codedata calx
    on calx.codetype = '[发明实审]出案类型'
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


--明细表旧sql3096
SELECT gl.gl_yxsc_ajscb_id,
       gl.shenqingh, --取固化
       gl.zhuanlilx, --取固化
       zhu.zhuanlimc,
       gl.shenqingrlx, --取固化
       gl.youxianscbh,
       gl.youxianscqqlx, --取固化
       gl.youxianscfs, --取固化
       gl.youxiansccjrq,
       gbb.bumc,
       gbb.chumc,
       gx.shishenscy,
       gx.shenqingr,
       gx.chushenhgr,
       gx.shishenscjar,
       gl.guobie,
       gl.shengfendm, --取固化
       gx.jkajscyjsr,
       gl.zhufenlh,
       gl.banlifs, --取固化
       gx.huianrq,
       gl.querensj, --取固化
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
              w.shenchayxm) as renyuanxm, --初审合格日期、
       gx.gongburq, --公布日期
       gx.jinrussrq, -- 进入实审日期
       sab.sstar, --实申提案日
       gx.yitongfwr, --一通发文日期
       gl.anjianzt,
       ajzt.codename as anjianzt_mc, --首次结案日
       gx.chuanlx, --首次结案类型
       calx.codename as calxmc, --出案名称
       gl.chuzhengbm,
       czbm.chuzhengbmmc as chuzhengbm_mc,
       gb.codename as guobie_mc,
       qh.gjxzqhmc as shengfendm_mc, --加快案件审查员接收日
       gl.feiyongbh,
       decode(gl.feiyongclbj, '1', '是', '否') as feiyongclbj,
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
    on zllx.codetype = '优先审查专利类型'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '基本代码（国家和地区代码）'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[公共]案件状态代码'
   AND ajzt.CODEVALUE = gl.anjianzt
  left join codedata calx
    on calx.codetype = '[发明实审]出案类型'
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


--同义词
create or replace public synonym GL_YXSC_AJSCTJB
for GL_YXSC_AJSCTJB 

--导入数据从统计库到测试库
insert into GL_YXSC_AJSCTJB
select * from GL_YXSC_AJSCTJB@LINK_GLCX_SCZQ_USER;

insert into GL_YXSC_SCJAB
select * from GL_YXSC_SCJAB@LINK_GLCX_SCZQ_USER;

-- 明细查询新sql3068
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
       decode(gl.feiyongclbj, '1', '是', '否') as feiyongclbj,
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
--代码集
  left join codedata zllx
    on zllx.codetype = '优先审查专利类型'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '基本代码（国家和地区代码）'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[公共]案件状态代码'
   AND ajzt.CODEVALUE = gl.anjianzt
 WHERE gl.shanchubj = '0'
   and gl.youxianscqqrq >= '20120801'
   and gl.youxianscqqrq <= '20130831'

-- 多的那一件
select s.shanchubj,s.youxiansczt,s.* from gl_yxsc_ajscb s where shenqingh = '2013100013416'

select * from GL_YXSC_AJSCTJB where shenqingh = '2013100013416';
select * from GL_YXSC_SCJAB where shenqingh = '2013100013416';


--明细查询旧sql3802
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
       decode(gl.feiyongclbj, '1', '是', '否') as feiyongclbj,
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
    on zllx.codetype = '优先审查专利类型'
   AND zllx.CODEVALUE = gl.zhuanlilx
  left join codedata blfs
    on blfs.codetype = 'GL_JIAKUAI_BANLIFS'
   AND blfs.CODEVALUE = gl.banlifs
  left join codedata sqrlx
    on sqrlx.codetype = 'GL_JIAKUAI_SQRLX'
   and sqrlx.codevalue = gl.shenqingrlx
  left join codedata gb
    on gb.codetype = '基本代码（国家和地区代码）'
   AND gb.CODEVALUE = gl.guobie
  left join codedata ajzt
    on ajzt.codetype = '[公共]案件状态代码'
   AND ajzt.CODEVALUE = gl.anjianzt
  left join zpt_sjwh_gjxzqh qh
    on qh.gjxzqhdm = gl.shengfendm
 WHERE gl.shanchubj = '0'
   and gl.querensj >= '20120801'
   and gl.querensj <= '20130831'
--和新sql比对
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

-- 明细查询新sql
select ac.SHENQINGH,ac.shenqingrlx,ac.shengfendm,ac.youxianscqqlx,ac.youxianscfs,ac.youxianscqqrq,ac.banlifs,ac.querensj,ac.zhuanlilx
from 
(SELECT a.SHENQINGH,a.shenqingrlx,a.shengfendm,a.youxianscqqlx,a.youxianscfs,a.youxianscqqrq,a.banlifs,a.querensj,a.zhuanlilx
FROM GL_YXSC_SCJAB A
UNION ALL
SELECT c.SHENQINGH,c.shenqingrlx,c.shengfendm,c.youxianscqqlx,c.youxianscfs,c.youxianscqqrq,c.banlifs,c.querensj,c.zhuanlilx
FROM GL_YXSC_AJSCTJB C
) ac
where ac.querensj between 20130801 and 20130831


-- 润钱新sql
SELECT B.*
  FROM (SELECT A.*
          FROM GL_YXSC_SCJAB A
        UNION ALL
        SELECT C.*, '', '', '', ''
          FROM GL_YXSC_AJSCTJB C
         -- 统计月份是所在当月
         -- WHERE TONGJIND || TONGJIYF = TO_CHAR(SYSDATE, 'YYYYMM')
       ) B
where B.querensj between 20130801 and 20130831
order by bumendm nulls first

select * from gl_yxsc_ajscb where shenqingh = '2010800690083'
select shenqingh ,count(*) from gl_yxsc_ajscb ac group by ac.shenqingh having count(*)>1
delete from GL_YXSC_AJSCTJB

select * from zpt_qxjs_qxdy

-- 优先审查首次结案数据
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
  from -- 在实审表查询首次结案日(最小质检出案日)
       (select ssxh.zhijiancar,
               ssxh.shuoshuscy,
               ssxh.shuoshujgid_fk,
               ssxh.shenqinghao
        --组内排序
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

-- 未结案数据
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
       ( -- 优先审查首次结案申请号
        select b.shenqingh
          from -- 在实审表有首次结案日(质检出案日)的申请号
                (select shenqinghao
                 --组内排序
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

-- 建立首次结案表
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
'优先审查首次结案表';
-- Add comments to the columns
comment on column GL_YXSC_SCJAB.tongjind is
'统计年度';
comment on column GL_YXSC_SCJAB.tongjiyf is
'统计月份';
comment on column GL_YXSC_SCJAB.zhijiancar is
'首次结案日（最小质检出案日）';
comment on column GL_YXSC_SCJAB.shuoshuscy is
'所属审查员（用户帐号）';
comment on column GL_YXSC_SCJAB.renyuanxm is
'所属审查员名称（人员姓名）';
comment on column GL_YXSC_SCJAB.shuoshujgid_fk is
'所属机构id';
drop table GL_YXSC_AJSCTJB

-- 建立案件审查统计表
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
-- 查询结果为空
  and 1 = 2;
-- Add comments to the table 
comment on table GL_YXSC_AJSCTJB is 
'案件审查统计表';
-- Add comments to the columns 
comment on column GL_YXSC_AJSCTJB.tongjiyf is
'统计月份';
comment on column GL_YXSC_AJSCTJB.tongjind is
'统计年度';

-- 润钱旧sql
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

-- 统计库：查询润前的表
-- 107513 admin 统计子系统 统计配置
select * from i_query t where t.uuid='0C1V0MVI6TDD42C5';
优先审查的统计表

-- 查询申请号错误
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
