#! /usr/bin/sh

pip install --no-warn-script-location -r python/requirement

rm .vscode/tasks.json || true
cp .vscode/tasks.sample.json .vscode/tasks.json
