#! /usr/bin/sh

rm -r ~/eosio-wallet/default.wallet || true
cleos wallet create --name default --file password.key
wp=$(cat password.key)
sed -i "s/insert-your-keosd-password-here/$wp/g" .vscode/tasks.json
rm password.key
