/*
Navicat MySQL Data Transfer

Source Server         : unis
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : userdb

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2013-09-22 08:51:39
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `usertable`
-- ----------------------------
DROP TABLE IF EXISTS `usertable`;
CREATE TABLE `usertable` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(255) NOT NULL,
  `user_password` varchar(255) NOT NULL,
  `user_sex` varchar(255) DEFAULT NULL,
  `user_city` varchar(255) DEFAULT NULL,
  `user_province` varchar(255) DEFAULT NULL,
  `user_hobby` varchar(255) DEFAULT NULL,
  `user_age` int(11) DEFAULT NULL,
  `user_describe` text,
  `user_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of usertable
-- ----------------------------
INSERT INTO usertable VALUES ('1', '谢秋鹏', '123123', '男', '济南', '山东', '篮球，足球，羽毛球，跑步', null, '个人介绍', '1');
