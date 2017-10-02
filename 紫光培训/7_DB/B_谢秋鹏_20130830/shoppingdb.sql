/*
Navicat MySQL Data Transfer

Source Server         : unis
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : shoppingdb

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2013-08-30 15:03:20
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `buyertable`
-- ----------------------------
DROP TABLE IF EXISTS `buyertable`;
CREATE TABLE `buyertable` (
  `buyer_id` int(11) NOT NULL AUTO_INCREMENT,
  `buyer_name` varchar(255) NOT NULL,
  `buyer_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`buyer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of buyertable
-- ----------------------------
INSERT INTO buyerTable VALUES ('1', '王群', '1');
INSERT INTO buyerTable VALUES ('2', '陆彤', '1');
INSERT INTO buyerTable VALUES ('3', '谢秋鹏', '1');
INSERT INTO buyerTable VALUES ('4', '夏成帮', '1');

-- ----------------------------
-- Table structure for `commoditytable`
-- ----------------------------
DROP TABLE IF EXISTS `commoditytable`;
CREATE TABLE `commoditytable` (
  `commodity_id` int(11) NOT NULL AUTO_INCREMENT,
  `commodity_name` varchar(255) NOT NULL,
  `commodity_display` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`commodity_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of commoditytable
-- ----------------------------
INSERT INTO commodityTable VALUES ('1', '轻松学Java', '1');
INSERT INTO commodityTable VALUES ('2', '轻松学数据库', '1');
INSERT INTO commodityTable VALUES ('3', '头巾', '1');
INSERT INTO commodityTable VALUES ('4', '衣服', '1');

-- ----------------------------
-- Table structure for `ordertable`
-- ----------------------------
DROP TABLE IF EXISTS `ordertable`;
CREATE TABLE `ordertable` (
  `order_id` int(11) NOT NULL AUTO_INCREMENT,
  `order_name` varchar(255) NOT NULL,
  `order_display` int(11) NOT NULL DEFAULT '1',
  `buyer_id` int(11) NOT NULL,
  `commodity_id` int(11) NOT NULL,
  PRIMARY KEY (`order_id`),
  KEY `orderbuyer_1` (`buyer_id`),
  KEY `ordercommodity_1` (`commodity_id`),
  CONSTRAINT `orderbuyer_1` FOREIGN KEY (`buyer_id`) REFERENCES `buyertable` (`buyer_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `ordercommodity_1` FOREIGN KEY (`commodity_id`) REFERENCES `commoditytable` (`commodity_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of ordertable
-- ----------------------------
INSERT INTO orderTable VALUES ('1', '图书音像', '1', '1', '1');
INSERT INTO orderTable VALUES ('2', '图书音像', '1', '1', '2');
INSERT INTO orderTable VALUES ('3', '美容化妆', '1', '2', '3');
INSERT INTO orderTable VALUES ('4', '美容化妆', '1', '2', '4');
