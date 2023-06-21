export default class Users {
    userList = [];
    _getUserIndex(login) {
        return this.userList.findIndex((user) => user.login === login);
    }
    addUser(user) {
        this.userList.push(user);
    }
    deleteUser(login) {
        this.userList.splice(this._getUserIndex(login), 1);
    }
    getUser(userId) {
        const index = this._getUserIndex(userId);
        return this.userList[index];
    }
    findByLogin(login) {
        return this.userList.find((user) => user.login === login);
    }
}
//# sourceMappingURL=Users.js.map