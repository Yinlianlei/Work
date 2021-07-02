package sql

var mainNet string ="https://ropsten.infura.io/v3/2e6d9331f74d472a9d47fe99f697ca2b"
func Connection2mysql()MySQLConnector{
	option := MysqlOptions{
		//Hostname: "127.0.0.1",
		Hostname: "47.102.215.193",
		Port: "3306",
		DbName: "eth_relay",
		User: "Yinlianlei",
		Password: "1114561520",
		TablePrefix: "eth_",
		MaxOpenConnections: 10,
		MaxIdleConnections:5,
		ConnMaxLifetime: 15,
	}
	tables := []interface{}{}
	tables = append(tables)//,TransactionLogCopyright{},TransactionLogPurchase{},Block{},TransactionScan{})
	mysql := NewMqSQLConnector(&option,tables)
	return mysql
}

func Connection2copy()MySQLConnector{
	option := MysqlOptions{
		//Hostname: "127.0.0.1",
		Hostname: "47.102.215.193",
		Port: "3306",
		DbName: "Copyright",
		User: "copy",
		Password: "Transation",
		//TablePrefix: "eth_",
		MaxOpenConnections: 10,
		MaxIdleConnections:5,
		ConnMaxLifetime: 15,
	}
	tables := []interface{}{}
	tables = append(tables,Wx_copyright{},Wx_purchase{},Wx_user{})
	mysql := NewMqSQLConnector(&option,tables)
	return mysql
}

func Connection2Huawei()MySQLConnector{
	option := MysqlOptions{
		//Hostname: "127.0.0.1",
		Hostname: "47.102.215.193",
		Port: "3306",
		DbName: "Huawei",
		User: "huawei",
		Password: "huawei",
		//TablePrefix: "Huawei_",
		MaxOpenConnections: 10,
		MaxIdleConnections:5,
		ConnMaxLifetime: 15,
	}
	tables := []interface{}{}
	tables = append(tables,Huawei_fid_info{},Huawei_evidence{},Huawei_grant2user{},Huawei_granted_user{},Huawei_course{},Huawei_student{},Huawei_memory{})
	mysql := NewMqSQLConnector(&option,tables)
	return mysql
}

func Sql_GetMainNet()string{
	return mainNet;
}