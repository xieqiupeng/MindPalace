/*
Navicat MySQL Data Transfer

Source Server         : unis
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : db_org

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2013-09-02 12:59:18
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `attendancetable`
-- ----------------------------
DROP TABLE IF EXISTS `attendancetable`;
CREATE TABLE `attendancetable` (
  `org_id` int(11) NOT NULL,
  `userinfo_id` int(11) NOT NULL,
  `attendance_state` varchar(50) NOT NULL,
  `attendance_datetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `attendance_updown` varchar(10) NOT NULL,
  `attendance_place` varchar(50) NOT NULL,
  `attendance_display` int(11) NOT NULL DEFAULT '1',
  KEY `FK_ATTENDAN_REFERENCE_ORG` (`org_id`),
  KEY `FK_ATTENDAN_REFERENCE_USERINFO` (`userinfo_id`),
  CONSTRAINT `FK_ATTENDAN_REFERENCE_USERINFO` FOREIGN KEY (`userinfo_id`) REFERENCES `userinfotable` (`userinfo_id`),
  CONSTRAINT `FK_ATTENDAN_REFERENCE_ORG` FOREIGN KEY (`org_id`) REFERENCES `orgtable` (`org_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of attendancetable
-- ----------------------------
INSERT INTO attendancetable VALUES ('3', '18', '迟到', '2013-09-02 12:58:10', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('3', '18', '迟到', '2013-09-02 12:58:10', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('3', '18', '迟到', '2013-09-02 12:58:10', '下午', '京外', '1');
INSERT INTO attendancetable VALUES ('3', '4', '迟到', '2013-09-02 12:58:10', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('3', '18', '迟到', '2013-09-02 12:58:11', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('2', '1', '未到', '2013-09-02 12:58:11', '上午', '京外', '1');
INSERT INTO attendancetable VALUES ('2', '2', '请假', '2013-09-02 12:58:11', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('2', '3', '请假', '2013-09-02 12:58:11', '上午', '京内', '1');
INSERT INTO attendancetable VALUES ('2', '5', '未到', '2013-09-02 12:58:11', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('2', '8', '未到', '2013-09-02 12:58:11', '下午', '京外', '1');
INSERT INTO attendancetable VALUES ('2', '1', '迟到', '2013-09-02 12:58:11', '下午', '京外', '1');
INSERT INTO attendancetable VALUES ('2', '2', '迟到', '2013-09-02 12:58:11', '下午', '京内', '1');
INSERT INTO attendancetable VALUES ('2', '3', '未到', '2013-09-02 12:58:11', '下午', '部内', '1');
INSERT INTO attendancetable VALUES ('2', '5', '迟到', '2013-09-02 12:58:11', '下午', '部内', '1');
INSERT INTO attendancetable VALUES ('2', '8', '迟到', '2013-09-02 12:58:12', '下午', '京外', '1');
INSERT INTO attendancetable VALUES ('3', '4', '迟到', '2013-09-02 12:58:12', '上午', '部内', '1');
INSERT INTO attendancetable VALUES ('3', '18', '按时', '2013-09-02 12:58:12', '上午', '部内', '1');

-- ----------------------------
-- Table structure for `orgtable`
-- ----------------------------
DROP TABLE IF EXISTS `orgtable`;
CREATE TABLE `orgtable` (
  `org_id` int(11) NOT NULL AUTO_INCREMENT,
  `org_higher` smallint(6) NOT NULL,
  `org_name` varchar(200) NOT NULL,
  `org_number` varchar(50) NOT NULL,
  `org_type` varchar(50) NOT NULL,
  `org_level` varchar(50) NOT NULL,
  `org_telphone` varchar(50) NOT NULL,
  `org_charge` varchar(50) NOT NULL,
  `org_address` text NOT NULL,
  `org_creatimete` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `org_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`org_id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of orgtable
-- ----------------------------
INSERT INTO orgtable VALUES ('1', '0', '信息中心', '01', '类型一', '一级', '010-66760010', '王剑南', '东办公楼510', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('2', '0', '中心领导', '0101', '类型一', '二级', '010-6676011', '唐国江', '东办公楼511', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('3', '0', '综合组', '0102', '类型一', '二级', '010-66760012', '李婉磊', '东办公楼512', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('4', '0', '总师办', '0103', '类型二', '二级', '010-66760013', '李涛', '东办公楼513', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('5', '0', '一室', '0104', '类型二', '二级', '010-66760014', '张一鸣', '408办公楼101-101', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('6', '0', '二室', '0105', '类型一', '二级', '010-66760015', '李鹏举', '408办公楼101-102', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('7', '0', '三室', '0106', '类型一', '二级', '010-66760016', '邓康', '综合大楼2楼', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('8', '0', '四室', '0107', '类型二', '二级', '010-66760017', '周士元', '综合大楼2楼', '2013-09-02 12:57:59', '1');
INSERT INTO orgtable VALUES ('9', '0', '五室', '0108', '类型二', '二级', '010-66760018', '李伟', '综合大楼4楼', '2013-09-02 12:57:59', '1');

-- ----------------------------
-- Table structure for `userinfotable`
-- ----------------------------
DROP TABLE IF EXISTS `userinfotable`;
CREATE TABLE `userinfotable` (
  `org_id` int(11) NOT NULL,
  `userinfo_id` int(11) NOT NULL AUTO_INCREMENT,
  `userinfo_loginname` varchar(500) NOT NULL,
  `userinfo_password` varchar(500) NOT NULL,
  `userinfo_realname` varchar(500) NOT NULL,
  `userinfo_number` varchar(500) NOT NULL,
  `userinfo_mobile` varchar(50) NOT NULL,
  `userinfo_creattime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `userinfo_address` text NOT NULL,
  `userinfo_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`userinfo_id`),
  KEY `FK_USERINFO_REFERENCE_ORG` (`org_id`),
  CONSTRAINT `FK_USERINFO_REFERENCE_ORG` FOREIGN KEY (`org_id`) REFERENCES `orgtable` (`org_id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of userinfotable
-- ----------------------------
INSERT INTO userinfotable VALUES ('2', '1', 'wangjiannan', 'wangjiannan', '王剑南', '00030', '15369874588', '2013-09-02 12:58:04', '河北省唐山', '1');
INSERT INTO userinfotable VALUES ('2', '2', 'admin', '123', '唐国江', '00001', '15369874587', '2013-09-02 12:58:04', '河北省唐山', '1');
INSERT INTO userinfotable VALUES ('2', '3', 'liwanlei', 'liwanlei', '李婉磊', '00002', '12587456985', '2013-09-02 12:58:04', '河南省郑州市', '1');
INSERT INTO userinfotable VALUES ('3', '4', 'jiajiangbing', 'jiajiangbing', '贾江冰', '00004', '15212698745', '2013-09-02 12:58:04', '河南省洛阳市', '1');
INSERT INTO userinfotable VALUES ('2', '5', 'lidonglei', 'lidonglei', '李冬蕾', '00005', '16987456325', '2013-09-02 12:58:04', '河南省开封市', '1');
INSERT INTO userinfotable VALUES ('4', '6', 'lindehu', 'lindehu', '林德虎', '00006', '13456783443', '2013-09-02 12:58:05', '河南省开封市', '1');
INSERT INTO userinfotable VALUES ('4', '7', 'dengkang', 'dengkang', '邓康', '00003', '15036987456', '2013-09-02 12:58:05', '河南省南阳市', '1');
INSERT INTO userinfotable VALUES ('2', '8', 'zhoushiyuan', 'zhoushiyuan', '周士元', '00009', '15036985263', '2013-09-02 12:58:05', '河南省信阳市', '1');
INSERT INTO userinfotable VALUES ('6', '9', 'wangcui', 'wangcui', '王翠', '00007', '13968541236', '2013-09-02 12:58:05', '河南省郑州市', '1');
INSERT INTO userinfotable VALUES ('5', '10', 'wangzhiqiang', 'wangzhiqiang', '王志强', '00013', '15036987456', '2013-09-02 12:58:05', '河南省洛阳市', '1');
INSERT INTO userinfotable VALUES ('8', '11', 'libingbing', 'libingbing', '李冰冰', '00016', '13669852364', '2013-09-02 12:58:05', '山东省菏泽市', '1');
INSERT INTO userinfotable VALUES ('9', '12', 'fanbingbing', 'fanbingbing', '范冰冰', '00017', '13665412368', '2013-09-02 12:58:05', '山东省威海市', '1');
INSERT INTO userinfotable VALUES ('7', '13', 'zhangyiming', 'zhangyiming', '张一鸣', '00010', '13668954126', '2013-09-02 12:58:05', '河南省焦作市', '1');
INSERT INTO userinfotable VALUES ('5', '14', 'zhangshi', 'zhangshi', '张石', '00011', '13685426587', '2013-09-02 12:58:05', '河南省信阳市', '1');
INSERT INTO userinfotable VALUES ('4', '15', 'zhangqicai', 'zhangqicai', '张奇才', '00012', '13889654126', '2013-09-02 12:58:05', '河南省洛阳市', '1');
INSERT INTO userinfotable VALUES ('6', '16', 'matianzhe', 'matianzhe', '马天哲', '00014', '15032698741', '2013-09-02 12:58:06', '河南省平顶山', '1');
INSERT INTO userinfotable VALUES ('7', '17', 'zhangfei', 'zhangfei', '张飞', '00031', '1331331393', '2013-09-02 12:58:06', '河南省信阳市', '1');
INSERT INTO userinfotable VALUES ('3', '18', 'litao', 'litao', '李涛', '00018', '18613879713', '2013-09-02 12:58:06', '河南省信阳市', '1');
