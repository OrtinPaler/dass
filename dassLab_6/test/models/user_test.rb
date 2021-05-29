# frozen_string_literal: true

require 'test_helper'

class UserTest < ActiveSupport::TestCase
  def setup
    @user = User.new(name: 'Ortin', email: 'paler@mail.ru', password: 'foobar', password_confirmation: 'foobar')
  end

  test 'пользователь должен быть валиден' do
    assert @user.valid?
  end

  test 'имя должно быть настоящим' do
    @user.name = '  '
    assert_not @user.valid?
  end

  test 'почта должна быть настоящая' do
    @user.email = '  '
    assert_not @user.valid?
  end

  test 'имя не должно быть слишком длинным' do
    @user.name = 'a' * 51
    assert_not @user.valid?
  end

  test 'почта не должна быть слишком длинной' do
    @user.email = "#{'a' * 244}@example.com"
    assert_not @user.valid?
  end

  test 'проверка почты должна принимать действительные адреса' do
    valid_addr = %w[user@example.com USER@foo.ru A_US-ER@foo.bar.org first.last@foo.jp alice+bob@baz.cn]
    valid_addr.each do |addr|
      @user.email = addr
      assert @user.valid?, "#{addr.inspect} должен быть действительный"
    end
  end

  test 'проверка почты должна отклонять недопустимые адреса' do
    invalid_addr = %w[user@example,com user_at_foo.org user.name@example. foo@bar_baz.com foo@bar+baz.com]
    invalid_addr.each do |addr|
      @user.email = addr
      assert_not @user.valid?, "#{addr.inspect} должно быть недействительный"
    end
  end

  test 'почтовые адреса должны быть уникальными' do
    duplicate_user = @user.dup
    duplicate_user.email = @user.email.upcase
    @user.save
    assert_not duplicate_user.valid?
  end

  test 'пароль должен иметь минимальную длину ' do
    @user.password = @user.password_confirmation = 'a' * 5
    assert_not @user.valid?
  end
end
