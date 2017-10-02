/*
Navicat MySQL Data Transfer

Source Server         : unis
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : class

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2013-08-30 15:03:44
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `classtable`
-- ----------------------------
DROP TABLE IF EXISTS `classtable`;
CREATE TABLE `classtable` (
  `class_id` int(11) NOT NULL AUTO_INCREMENT,
  `class_name` varchar(15) NOT NULL,
  `class_display` int(11) NOT NULL DEFAULT '1',
  `teacher_id` int(11) NOT NULL,
  PRIMARY KEY (`class_id`),
  KEY `classteacher_1` (`teacher_id`),
  CONSTRAINT `classteacher_1` FOREIGN KEY (`teacher_id`) REFERENCES `teachertable` (`teacher_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of classtable
-- ----------------------------
INSERT INTO classTable VALUES ('1', '计算103', '1', '1');
INSERT INTO classTable VALUES ('2', '计算101', '1', '2');

-- ----------------------------
-- Table structure for `coursetable`
-- ----------------------------
DROP TABLE IF EXISTS `coursetable`;
CREATE TABLE `coursetable` (
  `course_id` int(11) NOT NULL AUTO_INCREMENT,
  `course_name` varchar(255) NOT NULL,
  `teacher_id` int(11) NOT NULL,
  `course_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`course_id`),
  KEY `courseteacher_1` (`teacher_id`),
  CONSTRAINT `courseteacher_1` FOREIGN KEY (`teacher_id`) REFERENCES `teachertable` (`teacher_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of coursetable
-- ----------------------------

-- ----------------------------
-- Table structure for `studenttable`
-- ----------------------------
DROP TABLE IF EXISTS `studenttable`;
CREATE TABLE `studenttable` (
  `student_id` int(11) NOT NULL AUTO_INCREMENT,
  `student_name` varchar(10) NOT NULL,
  `student_display` int(11) NOT NULL DEFAULT '1',
  `class_id` int(11) NOT NULL,
  PRIMARY KEY (`student_id`),
  KEY `studentClass_1` (`class_id`),
  CONSTRAINT `studentClass_1` FOREIGN KEY (`class_id`) REFERENCES `classtable` (`class_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of studenttable
-- ----------------------------
INSERT INTO studentTable VALUES ('1', '王群', '1', '1');
INSERT INTO studentTable VALUES ('2', '陆彤', '1', '2');

-- ----------------------------
-- Table structure for `teachertable`
-- ----------------------------
DROP TABLE IF EXISTS `teachertable`;
CREATE TABLE `teachertable` (
  `teacher_id` int(11) NOT NULL AUTO_INCREMENT,
  `teacher_name` varchar(255) NOT NULL,
  `teacher_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`teacher_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of teachertable
-- ----------------------------
INSERT INTO teacherTable VALUES ('1', '李婉磊', '1');
INSERT INTO teacherTable VALUES ('2', '李涛', '1');
