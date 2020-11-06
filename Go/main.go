package main
import(
	//"fmt"
	//"time"
	//"encoding/json"
	//"math/big"
)


func main()  {
	//address:="0xba5660094ab4f87d535c628da1e9bbf571728e3704d313ba9c859f58eed1bec8"
	//Sql_SelectAthorCopyright("0x484d451ed72b1d242c9ae14f0f233f1ea81a95641bfc506077bf3c6c9bb25315")
	//TestGetLogByHash(address)
	//data := "0x484d451ed72b1d242c9ae14f0f233f1ea81a95641bfc506077bf3c6c9bb25315"
	//Sql_SelectAthorCopyright(data)
	//testSleep()
	//	mysql:=Connection2mysql()

	//RE,_ :=mysql.Db.IsTableEmpty("eth_block")
	//requestor := NewETHRPCRequester(mainNet)
	//fmt.Println(RE,err)
	TestBlockScanner_Start()
	//spider_contract("1")
	//Sql_SelectFromDatabase("data","eth_transaction_log_purchase","")
	//fmt.Println(time.Now().Format("2006-01-02 15:04:05"))
	/*
	mainNet := "https://mainnet.infura.io/v3/2e6d9331f74d472a9d47fe99f697ca2b"
	requestor := NewETHRPCRequester(mainNet)
	il,err := requestor.GetTransactionByHash(address)
	Jjson, _ := json.Marshal(il)
	fmt.Println(string(Jjson),err)
	*/
}