package model

import(
	//"github.com/ethereum/go-ethereum/core/types"
	//"math/big"
	"../sql"
)

type Transaction_Scan struct {
	Number           string   	`json:"number"`
	Hash             string 	`json:"hash"`
	ParentHash       string 	`json:"parentHash"`
	Nonce            string   	`json:"nonce"`
	//Sha3Uncles       string   	`json:"sha3Uncles"`
	//LogsBloom        string   	`json:"logsBloom"`
	//TransactionsRoot string   	`json:"transactionsRoot"`
	//ReceiptsRoot     string   	`json:"stateRoot"`
	//Miner            string   	`json:"miner"`
	//Difficulty       string   	`json:"difficulty"`
	//TotalDifficulty  string   	`json:"totalDifficulty"`
	//ExtraData        string   	`json:"extraData"`
	//Size             string   	`json:"size"`
	//GasLimit         string   	`json:"gasLimit"`
	//GasUsed          string   	`json:"gasUsed"`
	Timestamp        string   	`json:"timestamp"`
	//Uncles           []string   `json:"uncles"`
	Transactions 	 []sql.TransactionScan 	`json:"transactions"`
}