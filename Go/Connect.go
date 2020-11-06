package main
import(
	"./sql"
)

var mainNet string ="https://ropsten.infura.io/v3/2e6d9331f74d472a9d47fe99f697ca2b"

func Connection2mysql()sql.MySQLConnector{
	option := sql.MysqlOptions{
		Hostname: "127.0.0.1",
		Port: "3306",
		DbName: "eth_relay",
		//DbName: "tSQL",
		User: "Yinlianlei",
		Password: "1114561520",
		TablePrefix: "eth_",
		MaxOpenConnections: 10,
		MaxIdleConnections:5,
		ConnMaxLifetime: 15,
	}
	tables := []interface{}{}
	tables = append(tables,sql.TransactionLogCopyright{},sql.TransactionLogPurchase{},sql.Block{},sql.TransactionScan{})
	//tables = append(tables,sql.Tsql{})
	mysql := sql.NewMqSQLConnector(&option,tables)
	return mysql
}


func Connection2mysql_ts()sql.MySQLConnector{
	option := sql.MysqlOptions{
		//Hostname: "47.102.215.193",
		Hostname: "127.0.0.1",
		Port: "3306",
		DbName: "eth_relay",
		//DbName: "tSQL",
		User: "Yinlianlei",
		Password: "1114561520",
		TablePrefix: "eth_",
		MaxOpenConnections: 10,
		MaxIdleConnections:5,
		ConnMaxLifetime: 15,
	}
	tables := []interface{}{}
	tables = append(tables,sql.TransactionLogCopyright{},sql.TransactionLogPurchase{},sql.Block{},sql.TransactionScan{})
	//tables = append(tables,sql.Tsql{})
	mysql := sql.NewMqSQLConnector(&option,tables)
	return mysql
}