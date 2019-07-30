import React from 'react'

import Wemoji from './Wemoji'

const Bullet = () => (
  <div
    className="mr1 inline-block align-middle flex-none"
    style={{ width: 20, height: 20 }}
  >
    <Wemoji name="white-right-pointing-backhand-index" />
  </div>
)

const Details = ({ toggleModal }) => (
  <div className="px2 py4">
    <div className="container mx-auto">
      <div className="flex items-center justify-center">
        <div className="sm-col-6">
          <h2 className="mt0 h1">Get 'em today.</h2>
          <p className="mb2 h3 sm-col-10">
            Diverse set of emoji with all types of skin tones for everyone. Perfect for Discord, Slack, iPhone emoji, and computer keyboards. Full flexiblity to use on your apps, websites, and slide decks.
          </p>
          <div className="mb2 sm-col-11">
            <div className="py1 flex">
              <Bullet />
              <div>
                200+ icons (
                <button
                  type="button"
                  className="btn btn-link regular p0"
                  onClick={toggleModal}
                >
                  see full list
                </button>
                )
              </div>
            </div>
            <div className="py1 flex">
              <Bullet />
              <div>Four sizes for each emoji</div>
            </div>
            <div className="py1 flex">
              <Bullet />
              <div>
                <code>.gif and .svg</code> file format
              </div>
            </div>
          </div>
          <a
            className="gumroad-button"
            href="https://gum.co/divmoji"
            target="_blank"
            rel="noopener noreferrer"
            data-gumroad-single-product="true"
          >
            Purchase - $15
          </a>
        </div>
        <div className="sm-col-4 xs-hide py2">
          <Wemoji name="victory-hand" />
        </div>
      </div>
    </div>
  </div>
)

export default Details
