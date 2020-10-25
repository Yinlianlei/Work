package model

import(
	//"github.com/ethereum/go-ethereum/core/types"
	//"math/big"
)

type Transaction_log struct {
	//Hash             string    	`json:"hash"`
	//Nonce            string 	`json:"nonce"`
	//BlockHash        string    	`json:"blockHash"`
	//BlockNumber      string 	`json:"blockNumber"`
	//TransactionIndex string 	`json:"transactionIndex"`
	From             string    	`json:"from"`
	To               string    	`json:"to"`
	//Value            string 	`json:"value"`
	//GasPrice         string 	`json:"gasPrice"`
	//Gas              string 	`json:"gas"`
	//Input            string    	`json:"input"`
	//CumulativeGasUsed string `json:"CumulativeGasUsed"`
	//ContractAddress string `json:"contract_address"`
	//GasUsed  string`json:"gas_used"`
	Logs []Log `json:"Logs"`
	//LosgBloom string `json:"logsbloom"`
	//Root string `json:"root"`

}