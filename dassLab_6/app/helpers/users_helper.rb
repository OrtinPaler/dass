# frozen_string_literal: true

# helper for user
module UsersHelper
  # return user's gravatar
  def gravatar_for(user)
    # hashing the user's email
    gravatar_id = Digest::MD5.hexdigest(user.email.downcase)
    gravatar_url = "https://secure.gravatar.com/avatar/#{gravatar_id}"
    image_tag gravatar_url, alt: user.name, class: 'gravatar'
  end
end
