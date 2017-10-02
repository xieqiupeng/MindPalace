/*
Navicat MySQL Data Transfer

Source Server         : unis
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : userdb

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2013-09-14 11:13:06
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `classtable`
-- ----------------------------
DROP TABLE IF EXISTS `classtable`;
CREATE TABLE `classtable` (
  `class_id` int(11) NOT NULL AUTO_INCREMENT,
  `class_name` varchar(20) NOT NULL,
  `class_master` varchar(10) NOT NULL,
  `class_describe` varchar(100) NOT NULL,
  `class_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`class_id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of classtable
-- ----------------------------
INSERT INTO classtable VALUES ('1', '计算103', '曹建', '优秀班级', '1');
INSERT INTO classtable VALUES ('2', '计算102', '毛点辉', '优秀班级', '1');
INSERT INTO classtable VALUES ('3', '计算101', '马慧君', '普通班级', '1');
INSERT INTO classtable VALUES ('4', '软件101', '李涛', '重点班', '1');
INSERT INTO classtable VALUES ('5', '软件102', '李婉磊', '重点班', '1');

-- ----------------------------
-- Table structure for `coursetable`
-- ----------------------------
DROP TABLE IF EXISTS `coursetable`;
CREATE TABLE `coursetable` (
  `course_id` int(11) NOT NULL AUTO_INCREMENT,
  `course_name` varchar(255) NOT NULL,
  `teacher_id` varchar(255) NOT NULL,
  `course_describe` text NOT NULL,
  `course_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`course_id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of coursetable
-- ----------------------------
INSERT INTO coursetable VALUES ('1', 'HTML', '李婉磊', 'HTML', '1');
INSERT INTO coursetable VALUES ('2', 'CSS', '李涛', 'CSS', '1');
INSERT INTO coursetable VALUES ('3', 'JavaScript', '王剑南', 'JavaScript', '1');
INSERT INTO coursetable VALUES ('4', 'Java', '李涛', 'Java', '1');
INSERT INTO coursetable VALUES ('5', '计算机网络', '蔡青松', '计算机网络', '1');
INSERT INTO coursetable VALUES ('6', '操作系统', '赵霞', '操作系统', '1');
INSERT INTO coursetable VALUES ('7', 'Jquery', '李涛', 'Jquery', '1');

-- ----------------------------
-- Table structure for `sctable`
-- ----------------------------
DROP TABLE IF EXISTS `sctable`;
CREATE TABLE `sctable` (
  `course_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  `sc_grade` varchar(255) NOT NULL,
  PRIMARY KEY (`course_id`,`student_id`),
  KEY `scstudent` (`student_id`),
  CONSTRAINT `sccourse` FOREIGN KEY (`course_id`) REFERENCES `coursetable` (`course_id`),
  CONSTRAINT `scstudent` FOREIGN KEY (`student_id`) REFERENCES `studenttable` (`student_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of sctable
-- ----------------------------
INSERT INTO sctable VALUES ('1', '3', '1');
INSERT INTO sctable VALUES ('1', '4', '1');
INSERT INTO sctable VALUES ('1', '13', '1');
INSERT INTO sctable VALUES ('1', '14', '1');
INSERT INTO sctable VALUES ('1', '15', '1');
INSERT INTO sctable VALUES ('2', '3', '1');
INSERT INTO sctable VALUES ('2', '4', '1');
INSERT INTO sctable VALUES ('2', '13', '1');
INSERT INTO sctable VALUES ('2', '14', '1');
INSERT INTO sctable VALUES ('3', '3', '1');
INSERT INTO sctable VALUES ('3', '4', '1');
INSERT INTO sctable VALUES ('3', '13', '1');
INSERT INTO sctable VALUES ('3', '16', '1');
INSERT INTO sctable VALUES ('4', '3', '1');
INSERT INTO sctable VALUES ('4', '4', '1');
INSERT INTO sctable VALUES ('4', '6', '1');
INSERT INTO sctable VALUES ('4', '13', '1');
INSERT INTO sctable VALUES ('4', '15', '1');
INSERT INTO sctable VALUES ('4', '16', '1');
INSERT INTO sctable VALUES ('5', '3', '1');
INSERT INTO sctable VALUES ('5', '4', '1');
INSERT INTO sctable VALUES ('5', '5', '1');
INSERT INTO sctable VALUES ('5', '6', '1');
INSERT INTO sctable VALUES ('5', '13', '1');
INSERT INTO sctable VALUES ('5', '14', '1');
INSERT INTO sctable VALUES ('5', '15', '1');
INSERT INTO sctable VALUES ('5', '16', '1');
INSERT INTO sctable VALUES ('6', '3', '1');
INSERT INTO sctable VALUES ('6', '4', '1');
INSERT INTO sctable VALUES ('6', '5', '1');
INSERT INTO sctable VALUES ('6', '6', '1');
INSERT INTO sctable VALUES ('6', '14', '1');
INSERT INTO sctable VALUES ('6', '15', '1');
INSERT INTO sctable VALUES ('6', '16', '1');
INSERT INTO sctable VALUES ('7', '3', '1');
INSERT INTO sctable VALUES ('7', '4', '1');

-- ----------------------------
-- Table structure for `studenttable`
-- ----------------------------
DROP TABLE IF EXISTS `studenttable`;
CREATE TABLE `studenttable` (
  `student_id` int(11) NOT NULL AUTO_INCREMENT,
  `class_id` int(11) NOT NULL,
  `student_name` varchar(10) NOT NULL,
  `student_sex` varchar(10) NOT NULL,
  `student_age` int(11) NOT NULL,
  `student_major` varchar(30) NOT NULL,
  `student_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`student_id`),
  KEY `studentclass` (`class_id`),
  CONSTRAINT `studentclass` FOREIGN KEY (`class_id`) REFERENCES `classtable` (`class_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of studenttable
-- ----------------------------
INSERT INTO studenttable VALUES ('1', '4', '谢秋鹏', '男', '22', '软件工程', '0');
INSERT INTO studenttable VALUES ('2', '1', '谢秋鹏', '男', '22', '软件工程', '0');
INSERT INTO studenttable VALUES ('3', '3', '陆彤', '女', '22', '计算机科学与技术', '1');
INSERT INTO studenttable VALUES ('4', '1', '王群', '男', '22', '计算机科学与技术', '1');
INSERT INTO studenttable VALUES ('5', '1', '王同禄', '男', '22', '软件工程', '1');
INSERT INTO studenttable VALUES ('6', '4', '谢雨', '男', '22', '软件工程', '1');
INSERT INTO studenttable VALUES ('10', '1', '谢秋鹏', '男', '22', '软件工程', '0');
INSERT INTO studenttable VALUES ('11', '1', '谢秋鹏', '男', '22', '软件工程', '0');
INSERT INTO studenttable VALUES ('12', '1', '谢秋鹏', '男', '22', '软件工程', '0');
INSERT INTO studenttable VALUES ('13', '1', '谢秋鹏', '男', '22', '软件工程', '0');
INSERT INTO studenttable VALUES ('14', '4', '秦雪涛', '男', '22', '软件工程', '1');
INSERT INTO studenttable VALUES ('15', '5', '蒋仲伯', '男', '22', '软件工程', '1');
INSERT INTO studenttable VALUES ('16', '5', '赵申', '男', '22', '软件工程', '1');

-- ----------------------------
-- Table structure for `usertable`
-- ----------------------------
DROP TABLE IF EXISTS `usertable`;
CREATE TABLE `usertable` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(255) NOT NULL,
  `user_password` varchar(255) NOT NULL,
  `user_sex` varchar(255) NOT NULL,
  `user_age` int(11) NOT NULL,
  `user_describe` text,
  `user_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of usertable
-- ----------------------------
