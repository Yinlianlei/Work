package sql
import "fmt"

func Test_NewMqSQLConnector(){
	option := MysqlOptions{
		Hostname: "127.0.0.1",
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
	tables = append(tables,Block{},Transaction{})
	mysql :=NewMqSQLConnector(&option, tables)
	if mysql.Db.Ping() != nil{
		fmt.Println("Failed")
	}else{
		fmt.Println("Success")
	}
}